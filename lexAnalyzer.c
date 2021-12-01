#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//checks if the charater is a delimiter
bool Delimit(char ch){
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
		return (true);
		return (false);
}

//Checks if the character is operator
bool Operator(char ch){
if (ch == '+' || ch == '-' || ch == '*' ||ch == '/' || ch == '>' || ch == '<' || ch == '=')
	return (true);
	return (false);
}

//checks if the character is a valid identifier
bool validIdentifier(char* str){
if (str[0] == '0' || str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5' || str[0] == '6' || str[0] == '7' || str[0] == '8' ||  str[0] == '9' || Delimit(str[0]) == true)
	return (false);
	return (true);
}

//Check if the character is a Keyword
bool Keyword(char* str){

if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") || !strcmp(str, "do-while") || !strcmp(str, "foreach") || !strcmp(str, "continue") || !strcmp(str, "int")|| !strcmp(str, "double") || !strcmp(str, "float")|| !strcmp(str, "return") || !strcmp(str, "char")|| !strcmp(str, "case") || !strcmp(str, "block")|| !strcmp(str, "sizeof") || !strcmp(str, "long")|| !strcmp(str, "assignment") || !strcmp(str, "public")|| !strcmp(str, "switch") || !strcmp(str, "void") || !strcmp(str, "static")
|| !strcmp(str, "goto") || !strcmp(str, "struct"))
	return (true);
	return (false);
}

//Checks if the character is a valid integer
bool Integer(char* str)
{
int i, len = strlen(str);
if (len == 0)
	return (false);
for (i = 0; i < len; i++) {
if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
	return (false);
}
return (true);
}

//Checks if the character is a valid real number
bool RealNum(char* str)
{
int i, len = strlen(str);
bool hasDecimal = false;
if (len == 0)
return (false);
for (i = 0; i < len; i++) {
if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' ||
(str[i] == '-' && i > 0))
return (false);
if (str[i] == '.')
hasDecimal = true;
}
return (hasDecimal);
}


char* subString(char* str, int left, int right)
{
int i;
char* subStr = (char*)malloc(
sizeof(char) * (right - left + 2));
for (i = left; i <= right; i++)
subStr[i - left] = str[i];
subStr[right - left + 1] = '\0';
return (subStr);
}
//Parsing function
void parse(char* str)
{
	int left = 0, right = 0;
	int len = strlen(str);
	while (right <= len && left <= right) {
		if (Delimit(str[right]) == false)
		right++;
		if (Delimit(str[right]) == true && left == right) {
		if (Operator(str[right]) == true)
			printf("'%c' IS AN OPERATOR\n", str[right]);
			right++;
			left = right;
	} 
	else if (Delimit(str[right]) == true && left != right || (right == len && left != right)) {
	char* subStr = subString(str, left, right - 1);
	if (Keyword(subStr) == true)
		printf("'%s' IS A KEYWORD\n", subStr);
	else if (Integer(subStr) == true)
		printf("'%s' IS AN INTEGER\n", subStr);
	else if (RealNum(subStr) == true)
		printf("'%s' IS A REAL NUMBER\n", subStr);
	else if (validIdentifier(subStr) == true && Delimit(str[right - 1]) == false)
		printf("'%s' IS A VALID IDENTIFIER\n", subStr);
	else if (validIdentifier(subStr) == false && Delimit(str[right - 1]) == false)
		printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);

left = right;
}
}
return;
}

//Main function
int main()
{	
	// takes a file as input
    FILE *fpointer;
    fpointer = fopen("Lex.txt", "r");
    while (!feof(fpointer))
    {
        char str[100];
        fgets(str, 100, fpointer);
        parse(str);
    }
    fclose(fpointer);
    
	/*char str[100] = "int l = m  * 5 ";
	parse(str);
	return (0);
    */
}