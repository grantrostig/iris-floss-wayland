/* Iris floss is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Iris floss is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Iris floss.  If not, see <http://www.gnu.org/licenses/>.

   Original work Copyright (c) 2017 Daniel Georgiev <daniel@iristech.co>
*/

////////////////////////////////////////////////////////////
int maximum_red = 64;
int maximum_green = 64;
int maximum_blue = 64;

int maximum_brightness = 100;


////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

////////////////////////////////////////////////////////////
static float color_temperature[] = {
	1.00000000f, 0.00000000f, 0.00000000f,
	1.00000000f, 0.01817271f, 0.00000000f,
	1.00000000f, 0.03634543f, 0.00000000f,
	1.00000000f, 0.05451814f, 0.00000000f,
	1.00000000f, 0.07269086f, 0.00000000f,
	1.00000000f, 0.09086358f, 0.00000000f,
	1.00000000f, 0.10903629f, 0.00000000f,
	1.00000000f, 0.12720901f, 0.00000000f,
	1.00000000f, 0.14538172f, 0.00000000f,
	1.00000000f, 0.16355444f, 0.00000000f,
	1.00000000f, 0.18172716f, 0.00000000f,
	1.00000000f, 0.25503671f, 0.00000000f,
	1.00000000f, 0.30942099f, 0.00000000f, 
	1.00000000f, 0.35357379f, 0.00000000f,
	1.00000000f, 0.39091524f, 0.00000000f,
	1.00000000f, 0.42322816f, 0.00000000f,
	1.00000000f, 0.45159884f, 0.00000000f,
	1.00000000f, 0.47675916f, 0.00000000f,
	1.00000000f, 0.49923747f, 0.00000000f,
	1.00000000f, 0.51943421f, 0.00000000f,
	1.00000000f, 0.54360078f, 0.08679949f,
	1.00000000f, 0.56618736f, 0.14065513f,
	1.00000000f, 0.58734976f, 0.18362641f,
	1.00000000f, 0.60724493f, 0.22137978f,
	1.00000000f, 0.62600248f, 0.25591950f,
	1.00000000f, 0.64373109f, 0.28819679f,
	1.00000000f, 0.66052319f, 0.31873863f,
	1.00000000f, 0.67645822f, 0.34786758f,
	1.00000000f, 0.69160518f, 0.37579588f,
	1.00000000f, 0.70602449f, 0.40267128f,
	1.00000000f, 0.71976951f, 0.42860152f,
	1.00000000f, 0.73288760f, 0.45366838f,
	1.00000000f, 0.74542112f, 0.47793608f,
	1.00000000f, 0.75740814f, 0.50145662f,
	1.00000000f, 0.76888303f, 0.52427322f,
	1.00000000f, 0.77987699f, 0.54642268f,
	1.00000000f, 0.79041843f, 0.56793692f,
	1.00000000f, 0.80053332f, 0.58884417f,
	1.00000000f, 0.81024551f, 0.60916971f,
	1.00000000f, 0.81957693f, 0.62893653f,
	1.00000000f, 0.82854786f, 0.64816570f,
	1.00000000f, 0.83717703f, 0.66687674f,
	1.00000000f, 0.84548188f, 0.68508786f,
	1.00000000f, 0.85347859f, 0.70281616f,
	1.00000000f, 0.86118227f, 0.72007777f,
	1.00000000f, 0.86860704f, 0.73688797f,
	1.00000000f, 0.87576611f, 0.75326132f,
	1.00000000f, 0.88267187f, 0.76921169f,
	1.00000000f, 0.88933596f, 0.78475236f,
	1.00000000f, 0.89576933f, 0.79989606f,
	1.00000000f, 0.90198230f, 0.81465502f,
	1.00000000f, 0.90963069f, 0.82838210f,
	1.00000000f, 0.91710889f, 0.84190889f,
	1.00000000f, 0.92441842f, 0.85523742f,
	1.00000000f, 0.93156127f, 0.86836903f,
	1.00000000f, 0.93853986f, 0.88130458f,
	1.00000000f, 0.94535695f, 0.89404470f,
	1.00000000f, 0.95201559f, 0.90658983f,
	1.00000000f, 0.95851906f, 0.91894041f,
	1.00000000f, 0.96487079f, 0.93109690f,
	1.00000000f, 0.97107439f, 0.94305985f,
	1.00000000f, 0.97713351f, 0.95482993f,
	1.00000000f, 0.98305189f, 0.96640795f,
	1.00000000f, 0.98883326f, 0.97779486f,
	1.00000000f, 0.99448139f, 0.98899179f,
	1.00000000f, 1.00000000f, 1.00000000f,
	0.98947904f, 0.99348723f, 1.00000000f,
	0.97940448f, 0.98722715f, 1.00000000f,
	0.96975025f, 0.98120637f, 1.00000000f,
	0.96049223f, 0.97541240f, 1.00000000f,
	0.95160805f, 0.96983355f, 1.00000000f,
	0.94303638f, 0.96443333f, 1.00000000f,
	0.93480451f, 0.95923080f, 1.00000000f,
	0.92689056f, 0.95421394f, 1.00000000f,
	0.91927697f, 0.94937330f, 1.00000000f,
	0.91194747f, 0.94470005f, 1.00000000f,
	0.90488690f, 0.94018594f, 1.00000000f,
	0.89808115f, 0.93582323f, 1.00000000f,
	0.89151710f, 0.93160469f, 1.00000000f,
	0.88518247f, 0.92752354f, 1.00000000f,
	0.87906581f, 0.92357340f, 1.00000000f,
	0.87315640f, 0.91974827f, 1.00000000f,
	0.86744421f, 0.91604254f, 1.00000000f,
	0.86191983f, 0.91245088f, 1.00000000f,
	0.85657444f, 0.90896831f, 1.00000000f,
	0.85139976f, 0.90559011f, 1.00000000f,
	0.84638799f, 0.90231183f, 1.00000000f,
	0.84153180f, 0.89912926f, 1.00000000f,
	0.83682430f, 0.89603843f, 1.00000000f,
	0.83225897f, 0.89303558f, 1.00000000f,
	0.82782969f, 0.89011714f, 1.00000000f,
	0.82353066f, 0.88727974f, 1.00000000f,
	0.81935641f, 0.88452017f, 1.00000000f,
	0.81530175f, 0.88183541f, 1.00000000f,
	0.81136180f, 0.87922257f, 1.00000000f,
	0.80753191f, 0.87667891f, 1.00000000f,
	0.80380769f, 0.87420182f, 1.00000000f,
	0.80018497f, 0.87178882f, 1.00000000f,
	0.79665980f, 0.86943756f, 1.00000000f,
	0.79322843f, 0.86714579f, 1.00000000f,
	0.78988728f, 0.86491137f, 1.00000000f
};

////////////////////////////////////////////////////////////
int main(int argc, char **argv) 
{
	if(geteuid() != 0)
	{
		printf("You must run this program as Root\n");
		return -1;
	}

	// Get Color temperature
	int temperature = 3400;
	if (argc > 1)
	{
 		temperature = (int)atoi(argv[1]);
	}

	// Validate Color temperature
	if (temperature < 0) 
	{ 
		temperature = 0;
	}
	if (temperature > 10000)
	{
		temperature = 10000; 
	}

	// Get Brightness
	float brightness = 0.80f;
	if (argc > 2)
	{
		brightness = (float)atof(argv[2])/100.f;
	}
	
	// Validate Brightness
	if(brightness < 0.0f)
	{
		brightness = 0.0f;
	}
	if(brightness > 1.0f) 
	{
		brightness = 1.0f;
	}

	// Verbose output
	int verbose = 0;
	if (argc > 3)
	{
		if(strcmp (argv[3],"-v") == 0)
		{
			verbose = 1;
		}
	}

	int index = ((temperature) / 100)*3;

	int red_gamma = color_temperature[index] * (maximum_red/2);
	int green_gamma = color_temperature[index + 1] * (maximum_green/2);
	int blue_gamma = color_temperature[index + 2] * (maximum_blue/2);
	int monitor_brightness = brightness * maximum_brightness;

	char* set_monitor_red_gamma_cmd = malloc(1000);
	char* set_monitor_green_gamma_cmd = malloc(1000);
	char* set_monitor_blue_gamma_cmd = malloc(1000);
	char* set_monitor_brightness_cmd = malloc(1000);

	char* set_red_gamma = "ddccontrol -p -r 0x16 -w ";
	char* set_green_gamma = "ddccontrol -p -r 0x18 -w ";
	char* set_blue_gamma = "ddccontrol -p -r 0x1a -w ";
	char* set_brightness = "ddccontrol -p -r 0x10 -w ";

	char* skip_output = " >/dev/null 2>&1";
	if(verbose != 0)
	{
		skip_output = "";
	}

	sprintf(set_monitor_red_gamma_cmd, "%s%d%s", set_red_gamma, red_gamma, skip_output);
	sprintf(set_monitor_green_gamma_cmd, "%s%d%s", set_green_gamma, green_gamma, skip_output);
	sprintf(set_monitor_blue_gamma_cmd, "%s%d%s", set_blue_gamma, blue_gamma, skip_output);
	sprintf(set_monitor_brightness_cmd, "%s%d%s", set_brightness, monitor_brightness, skip_output);

	if(verbose != 0)
	{
		printf("%s\n", set_monitor_red_gamma_cmd);
		printf("%s\n", set_monitor_green_gamma_cmd);
		printf("%s\n", set_monitor_blue_gamma_cmd);
		printf("%s\n", set_monitor_brightness_cmd);
	}

	system(set_monitor_red_gamma_cmd); // Set Red
	system(set_monitor_green_gamma_cmd); // Set Green
	system(set_monitor_blue_gamma_cmd); // Set Blue
	system(set_monitor_brightness_cmd); // Set Brightness

	printf("Temperature set to %dK\n", temperature);
	printf("Brightness  set to %d%%\n", (int)(brightness * 100));

	return 0;
}

////////////////////////////////////////////////////////////
