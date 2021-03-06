// country name and positions
#include <QString>

#define NUM_COUNTRIES	267

struct Country {
    QString name;
    float lon, lat;
};

Country countries[NUM_COUNTRIES] = {

    {"Aruba", 12.5000, -69.9667},
    {"Antigua and Barbuda", 17.0500, -61.8000},
    {"Afghanistan", 33.0000, 65.0000},
    {"Algeria", 28.0000, 3.0000},
    {"Azerbaijan", 40.5000, 47.5000},
    {"Albania", 41.0000, 20.0000},
    {"Armenia", 40.0000, 45.0000},
    {"Andorra", 42.5000, 1.5000},
    {"Angola", -12.5000, 18.5000},
    {"American Samoa", -14.3333, -170.0000},
    {"Argentina", -34.0000, -64.0000},
    {"Australia", -27.0000, 133.0000},
    {"Ashmore and Cartier Islands", -12.2333, 123.0833},
    {"Austria", 47.3333, 13.3333},
    {"Anguilla", 18.2500, -63.1667},
    {"Antarctica", -90.0000, 0.0000},
    {"Bahrain", 26.0000, 50.5500},
    {"Barbados", 13.1667, -59.5333},
    {"Botswana", -22.0000, 24.0000},
    {"Bermuda", 32.3333, -64.7500},
    {"Belgium", 50.8333, 4.0000},
    {"Bahamas, The", 24.2500, -76.0000},
    {"Bangladesh", 24.0000, 90.0000},
    {"Belize", 17.2500, -88.7500},
    {"Bosnia and Herzegovina", 44.0000, 18.0000},
    {"Bolivia", -17.0000, -65.0000},
    {"Burma", 22.0000, 98.0000},
    {"Benin", 9.5000, 2.2500},
    {"Belarus", 53.0000, 28.0000},
    {"Solomon Islands", -8.0000, 159.0000},
    {"Navassa Island", 18.4167, -75.0333},
    {"Brazil", -10.0000, -55.0000},
    {"Bassas da India", -21.5000, 39.8333},
    {"Bhutan", 27.5000, 90.5000},
    {"Bulgaria", 43.0000, 25.0000},
    {"Bouvet Island", -54.4333, 3.4000},
    {"Brunei", 4.5000, 114.6667},
    {"Burundi", -3.5000, 30.0000},
    {"Canada", 60.0000, -95.0000},
    {"Cambodia", 13.0000, 105.0000},
    {"Chad", 15.0000, 19.0000},
    {"Sri Lanka", 7.0000, 81.0000},
    {"Congo, Republic of the", -1.0000, 15.0000},
    {"Congo, Democratic Republic of the", 0.0000, 25.0000},
    {"China", 35.0000, 105.0000},
    {"Chile", -30.0000, -71.0000},
    {"Cayman Islands", 19.5000, -80.5000},
    {"Cocos (Keeling) Islands", -12.5000, 96.8333},
    {"Cameroon", 6.0000, 12.0000},
    {"Comoros", -12.1667, 44.2500},
    {"Colombia", 4.0000, -72.0000},
    {"Northern Mariana Islands", 15.2000, 145.7500},
    {"Coral Sea Islands", -18.0000, 152.0000},
    {"Costa Rica", 10.0000, -84.0000},
    {"Central African Republic", 7.0000, 21.0000},
    {"Cuba", 21.5000, -80.0000},
    {"Cape Verde", 16.0000, -24.0000},
    {"Cook Islands", -21.2333, -159.7667},
    {"Cyprus", 35.0000, 33.0000},
    {"Denmark", 56.0000, 10.0000},
    {"Djibouti", 11.5000, 43.0000},
    {"Dominica", 15.4167, -61.3333},
    {"Jarvis Island", -0.3667, -160.0500},
    {"Dominican Republic", 19.0000, -70.6667},
    {"Ecuador", -2.0000, -77.5000},
    {"Egypt", 27.0000, 30.0000},
    {"Ireland", 53.0000, -8.0000},
    {"Equatorial Guinea", 2.0000, 10.0000},
    {"Estonia", 59.0000, 26.0000},
    {"Eritrea", 15.0000, 39.0000},
    {"El Salvador", 13.8333, -88.9167},
    {"Ethiopia", 8.0000, 38.0000},
    {"Europa Island", -22.3333, 40.3667},
    {"Czech Republic", 49.7500, 15.5000},
    {"Falkland Islands (Islas Malvinas)", -51.7500, -59.0000},
    {"French Guiana", 4.0000, -53.0000},
    {"Finland", 64.0000, 26.0000},
    {"Fiji", -18.0000, 175.0000},
    {"Micronesia, Federated States of", 6.9167, 158.2500},
    {"Faroe Islands", 62.0000, -7.0000},
    {"French Polynesia", -15.0000, -140.0000},
    {"Baker Island", 0.2167, -176.5167},
    {"France", 46.0000, 2.0000},
    {"French Southern and Antarctic Lands", -43.0000, 67.0000},
    {"Gambia, The", 13.4667, -16.5667},
    {"Gabon", -1.0000, 11.7500},
    {"Georgia", 42.0000, 43.5000},
    {"Ghana", 8.0000, -2.0000},
    {"Gibraltar", 36.1833, -5.3667},
    {"Grenada", 12.1167, -61.6667},
    {"Guernsey", 49.4667, -2.5833},
    {"Greenland", 72.0000, -40.0000},
    {"Germany", 51.0000, 9.0000},
    {"Glorioso Islands", -11.5000, 47.3333},
    {"Guadeloupe", 16.2500, -61.5833},
    {"Guam", 13.4667, 144.7833},
    {"Greece", 39.0000, 22.0000},
    {"Guatemala", 15.5000, -90.2500},
    {"Guinea", 11.0000, -10.0000},
    {"Guyana", 5.0000, -59.0000},
    {"Gaza Strip", 31.4167, 34.3333},
    {"Haiti", 19.0000, -72.4167},
    {"Hong Kong", 22.2500, 114.1667},
    {"Heard Island and McDonald Islands", -53.1000, 72.5167},
    {"Honduras", 15.0000, -86.5000},
    {"Howland Island", 0.8000, -176.6333},
    {"Croatia", 45.1667, 15.5000},
    {"Hungary", 47.0000, 20.0000},
    {"Iceland", 65.0000, -18.0000},
    {"Indonesia", -5.0000, 120.0000},
    {"Man, Isle of", 54.2500, -4.5000},
    {"India", 20.0000, 77.0000},
    {"British Indian Ocean Territory", -6.0000, 71.5000},
    {"Clipperton Island", 10.2833, -109.2167},
    {"Iran", 32.0000, 53.0000},
    {"Israel", 31.5000, 34.7500},
    {"Italy", 42.8333, 12.8333},
    {"Cote d'Ivoire", 8.0000, -5.0000},
    {"Iraq", 33.0000, 44.0000},
    {"Japan", 36.0000, 138.0000},
    {"Jersey", 49.2500, -2.1667},
    {"Jamaica", 18.2500, -77.5000},
    {"Jan Mayen", 71.0000, -8.0000},
    {"Jordan", 31.0000, 36.0000},
    {"Johnston Atoll", 16.7500, -169.5167},
    {"Juan de Nova Island", -17.0500, 42.7500},
    {"Kenya", 1.0000, 38.0000},
    {"Kyrgyzstan", 41.0000, 75.0000},
    {"Korea, North", 40.0000, 127.0000},
    {"Kingman Reef", 6.4000, -162.4000},
    {"Kiribati", 1.4167, 173.0000},
    {"Korea, South", 37.0000, 127.5000},
    {"Christmas Island", -10.5000, 105.6667},
    {"Kuwait", 29.5000, 45.7500},
    {"Kazakhstan", 48.0000, 68.0000},
    {"Laos", 18.0000, 105.0000},
    {"Lebanon", 33.8333, 35.8333},
    {"Latvia", 57.0000, 25.0000},
    {"Lithuania", 56.0000, 24.0000},
    {"Liberia", 6.5000, -9.5000},
    {"Slovakia", 48.6667, 19.5000},
    {"Palmyra Atoll", 5.8667, -162.1000},
    {"Liechtenstein", 47.1667, 9.5333},
    {"Lesotho", -29.5000, 28.5000},
    {"Luxembourg", 49.7500, 6.1667},
    {"Libya", 25.0000, 17.0000},
    {"Madagascar", -20.0000, 47.0000},
    {"Martinique", 14.6667, -61.0000},
    {"Macau", 22.1667, 113.5500},
    {"Moldova", 47.0000, 29.0000},
    {"Mayotte", -12.8333, 45.1667},
    {"Mongolia", 46.0000, 105.0000},
    {"Montserrat", 16.7500, -62.2000},
    {"Malawi", -13.5000, 34.0000},
    {"Macedonia, The Former Yugoslav Republic of", 41.8333, 22.0000},
    {"Mali", 17.0000, -4.0000},
    {"Monaco", 43.7333, 7.4000},
    {"Morocco", 32.0000, -5.0000},
    {"Mauritius", -20.2833, 57.5500},
    {"Midway Islands", 28.2167, -177.3667},
    {"Mauritania", 20.0000, -12.0000},
    {"Malta", 35.8333, 14.5833},
    {"Oman", 21.0000, 57.0000},
    {"Maldives", 3.2500, 73.0000},
    {"Mexico", 23.0000, -102.0000},
    {"Malaysia", 2.5000, 112.5000},
    {"Mozambique", -18.2500, 35.0000},
    {"New Caledonia", -21.5000, 165.5000},
    {"Niue", -19.0333, -169.8667},
    {"Norfolk Island", -29.0333, 167.9500},
    {"Niger", 16.0000, 8.0000},
    {"Vanuatu", -16.0000, 167.0000},
    {"Nigeria", 10.0000, 8.0000},
    {"Netherlands", 52.5000, 5.7500},
    {"Norway", 62.0000, 10.0000},
    {"Nepal", 28.0000, 84.0000},
    {"Nauru", -0.5333, 166.9167},
    {"Suriname", 4.0000, -56.0000},
    {"Netherlands Antilles", 12.2500, -68.7500},
    {"Nicaragua", 13.0000, -85.0000},
    {"New Zealand", -41.0000, 174.0000},
    {"Southern Ocean", -65.0000, 0.0000},
    {"Paraguay", -23.0000, -58.0000},
    {"Pitcairn Islands", -25.0667, -130.1000},
    {"Peru", -10.0000, -76.0000},
    {"Paracel Islands", 16.5000, 112.0000},
    {"Spratly Islands", 8.6333, 111.9167},
    {"Pakistan", 30.0000, 70.0000},
    {"Poland", 52.0000, 20.0000},
    {"Panama", 9.0000, -80.0000},
    {"Portugal", 39.5000, -8.0000},
    {"Papua New Guinea", -6.0000, 147.0000},
    {"Palau", 7.5000, 134.5000},
    {"Guinea-Bissau", 12.0000, -15.0000},
    {"Qatar", 25.5000, 51.2500},
    {"Reunion", -21.1000, 55.6000},
    {"Marshall Islands", 9.0000, 168.0000},
    {"Romania", 46.0000, 25.0000},
    {"Philippines", 13.0000, 122.0000},
    {"Puerto Rico", 18.2500, -66.5000},
    {"Russia", 60.0000, 100.0000},
    {"Rwanda", -2.0000, 30.0000},
    {"Saudi Arabia", 25.0000, 45.0000},
    {"Saint Pierre and Miquelon", 46.8333, -56.3333},
    {"Saint Kitts and Nevis", 17.3333, -62.7500},
    {"Seychelles", -4.5833, 55.6667},
    {"South Africa", -29.0000, 24.0000},
    {"Senegal", 14.0000, -14.0000},
    {"Saint Helena", -15.9333, -5.7000},
    {"Slovenia", 46.0000, 15.0000},
    {"Sierra Leone", 8.5000, -11.5000},
    {"San Marino", 43.7667, 12.4167},
    {"Singapore", 1.3667, 103.8000},
    {"Somalia", 10.0000, 49.0000},
    {"Spain", 40.0000, -4.0000},
    {"Saint Lucia", 13.8833, -61.1333},
    {"Sudan", 15.0000, 30.0000},
    {"Svalbard", 78.0000, 20.0000},
    {"Sweden", 62.0000, 15.0000},
    {"South Georgia and the South Sandwich Islands", -54.5000, -37.0000},
    {"Syria", 35.0000, 38.0000},
    {"Switzerland", 47.0000, 8.0000},
    {"United Arab Emirates", 24.0000, 54.0000},
    {"Trinidad and Tobago", 11.0000, -61.0000},
    {"Tromelin Island", -15.8667, 54.4167},
    {"Thailand", 15.0000, 100.0000},
    {"Tajikistan", 39.0000, 71.0000},
    {"Turks and Caicos Islands", 21.7500, -71.5833},
    {"Tokelau", -9.0000, -172.0000},
    {"Tonga", -20.0000, -175.0000},
    {"Togo", 8.0000, 1.1667},
    {"Sao Tome and Principe", 1.0000, 7.0000},
    {"Tunisia", 34.0000, 9.0000},
    {"Turkey", 39.0000, 35.0000},
    {"Tuvalu", -8.0000, 178.0000},
    {"Turkmenistan", 40.0000, 60.0000},
    {"Tanzania", -6.0000, 35.0000},
    {"Uganda", 1.0000, 32.0000},
    {"United Kingdom", 54.0000, -2.0000},
    {"Ukraine", 49.0000, 32.0000},
    {"United States", 38.0000, -97.0000},
    {"Burkina Faso", 13.0000, -2.0000},
    {"Uruguay", -33.0000, -56.0000},
    {"Uzbekistan", 41.0000, 64.0000},
    {"Saint Vincent and the Grenadines", 13.2500, -61.2000},
    {"Venezuela", 8.0000, -66.0000},
    {"British Virgin Islands", 18.5000, -64.5000},
    {"Vietnam", 16.0000, 106.0000},
    {"Virgin Islands", 18.3333, -64.8333},
    {"Holy See (Vatican City)", 41.9000, 12.4500},
    {"Namibia", -22.0000, 17.0000},
    {"Wallis and Futuna", -13.3000, -176.2000},
    {"Samoa", -13.5833, -172.3333},
    {"Swaziland", -26.5000, 31.5000},
    {"Indian Ocean", -20.0000, 80.0000},
    {"Arctic Ocean", 90.0000, 0.0000},
    {"Atlantic Ocean", 0.0000, -25.0000},
    {"Pacific Ocean", 0.0000, -160.0000},
    {"Wake Island", 19.2833, 166.6000},
    {"Western Sahara", 24.5000, -13.0000},
    {"Yemen", 15.0000, 48.0000},
    {"Zambia", -15.0000, 30.0000},
    {"Zimbabwe", -20.0000, 30.0000},
    {"Yugoslavia", 44.0000, 21.0000},
    {"West Bank", 32.0000, 35.2500},
    {"Taiwan", 23.5000, 121.0000}	};
