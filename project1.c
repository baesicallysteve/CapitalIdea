#include <stdio.h>
char alphaUppers[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
							'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
							'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

char alphaLowers[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
					'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
					'y', 'z'};
//Function getterline receives standard input
int getterline(char s[], int lim){
	int c, i;

	for(i = 0; i < lim -1 && (c = getchar())!= EOF && c != '\n'; i++)
		s[i] = c;
	if( c == '\n'){
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}
/*
	Function getAlphaNum will look at a character and give a numerical 
	representation if the character is within the alphabet. Or return a -1 
	if it isn't 
*/
int getAlphaNum(char character){
	int alpha_value = 0; // variable used to keep the values of characters
	int alpha_found = 0; // variable used to tell whether the character is found or not.
	/*
		Will check the character against every character in the Alphabet. 
		Lower Case and Upper Case and if the character is found will change the 
		value of alpha found to 1
	*/
	while(!(character == alphaLowers[alpha_value] || character == alphaUppers[alpha_value]) 
		&& alpha_value < 26){
		alpha_value++;
		}

	if(character == alphaLowers[alpha_value] || character == alphaUppers[alpha_value]){
		alpha_found = 1;
		}

		
	if(alpha_found == 1){
		return alpha_value;
		}
	else{
		return -1;
		}
}

/*
	Function isLowerrCase will go through a string and test every character to see
	which characters are lowercase will return a 1 if it is and -1 if it isn't.
*/

int isLowerCase(char s){
	int alphaNum = getAlphaNum(s);
	if (s == alphaLowers[alphaNum]){
		return 1;
	}

	else{
		return -1;
	}
}

/*
makeCaps takes a char array and an int and makes the first character a capital letter 
and then if there is a period at all it makes the next character a capital letter.
*/
int makeCaps(char string[],int lim){
	int i; // An increment variable

	// If the first character is a lower case letter, replace it with an upper case letter.
	if(isLowerCase(string[0]) == 1){
			string[0] = alphaUppers[getAlphaNum(string[0])];
			}
		for(i = 1; i < lim - 3; i++){

			// if there is a period and more characters and the next character is a lowercase letter than change it to an uppercase letter
			if(string[i] == '.' && i < lim && isLowerCase(string[i+3]) == 1){
				string[i+3] = alphaUppers[getAlphaNum(string[i+3])];
			}

	}
	return 1;
}

int isDoubleSpaced(char string[], int lim){
	int i;
	int isDoubled = 0;
	for(i = 0; i < lim; i++){
		if(string[i] == ' ' && string[i+1] == ' ')
			isDoubled = 1;
	}
	return isDoubled;
}

int addCharAt(char string[], int index,int lim, char character){
	if(index >= lim){
		return -1;
	}
	string[index] = character;
	return 1;
}
/*
	function doubleSpace takes a char array and a int value and then it checks 
	if there are any double spaces within the char array. If there are 
	the function takes the char array and then puts a period before the double space.
*/
int doubleSpace(char string[], int lim){
	int i; // an increment variable
	int j = 0;
	char temp1; 
	char temp2;
	char newString[lim];
	for(i = 0; i < lim; i++){

		//This statement makes sure that if there isn't already a period and a doublespace in the input, there will be 
		// a period
		if( string[i-1] != '.' && string[i] == ' ' && string[i+1] == ' '){
			addCharAt(string, i, lim, '.');
			
		}
		addCharAt(newString, i, lim, string[i]);
	}

	for(i = 0; i < lim; i++){
		//This statement will create the double spae effet by destroying the character array and then recreating it with
		// a copy of the original array
			if(string[i] == '.' && string[i+3] != ' '){
				addCharAt(string, i+2, lim, ' ');
				while(i < lim){
					addCharAt(string, i+3, lim, newString[i+2]);
					++i;
				}
			}
		}
		return 1;
	}

int main(){
	int lim = 991;
	char string[lim];
	getterline(string, lim);
	doubleSpace(string, lim);
	makeCaps(string, lim);
	printf("%s", string);
	return -1;
}
