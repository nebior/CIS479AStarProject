#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{

	int slength = 0, glength = 0, counter2 = 0, numberOfLines = 0, stringPosition = 0;
	string input, goal, stringForPath;
	bool valid = false, movePerformed = false, goalAttained = false;
	while (valid != true)
	{
		cout << "Input starting string: ";
		cin >> input;
		cout << "Input goal string: ";
		cin >> goal;
		char goalArray[1000];
		
		slength = input.size();
		glength = goal.size();
		if (slength != glength)
		{
			cout << "Strings are not same length. Re-input strings." << endl;
		}
		else
			valid = true;
	}
	char x[1][1000] , transfer[1][1000], test[1000];
	deque<string> paths;
	
		for (int j = 0; j < 1000; j++)//set entire char array to null
		{
			x[0][j] = '\0';
		}
	for (int j = 0; j < 1000; j++)//set entire char array to null
		{
			transfer[0][j] = '\0';
		}
	strcpy_s(x[0], input.c_str());
	paths.push_front(input);
	while(goalAttained == false){//while goal not attained
		while(counter2 < slength){ //run as many times as string is long

for (int j = 0; j < 1000; j++)//check to see it goal is reached
   {
    test[j] =x[0][j];
   }
   string tst(test);
   if (tst.substr(0,glength)==goal)
   {
    cout << tst << endl;
    system("pause");
    return 0;
   }
			
	if(x[0][counter2] == '(' || x[0][counter2] == '-'){ //Move left if hit (
		counter2++;
	}
	else if(x[0][counter2] == ')'){ //Move to next string when done with current string  ALL CHILDREN BORN: NOW SORT


		//SORT ABOVE
		stringPosition++;//increment position in string array
		counter2 = 0;
		paths.pop_back();
		input = paths.back();//set input to next string 
		strcpy_s(x[0], input.c_str());//set x[0] to input (the next srting)
	}
	else if(x[0][counter2+1] == '-'){  //if position to the right is -
		stringForPath.clear();
		
		for(int i = 0;i<slength;i++){
			transfer[0][i]=x[0][i];  //write newest path to next line
		}
		transfer[0][counter2+1]=x[0][counter2];//in new line move char to -
		transfer[0][counter2] = '-';//in new line put - where char was	
			int i = slength; //start writing after length of next line
			int j=0; //new counter
			while(x[0][j] != '\0'){ //until end of current line
			transfer[0][i]=x[0][j];//position in next line = info from this line
			i++;
			j++;
		}	
			int n = 0;
			while(transfer[0][n] != '\0'){
			stringForPath+=transfer[0][n];
			n++;
			}
			paths.push_front(stringForPath);
				numberOfLines++; //increment number of lines
					counter2++;
	}
	else if(x[0][counter2+2] == '-'){  //if position to the right is -
		stringForPath.clear();
		for(int i = 0;i<slength;i++){
			transfer[0][i]=x[0][i];  //write newest path to next line
		}
		transfer[0][counter2+2]=x[0][counter2];//in new line move char to -
		transfer[0][counter2] = '-';//in new line put - where char was	
			int i = slength; //start writing after length of next line
			int j=0; //new counter
			while(x[0][j] != '\0'){ //until end of current line
			transfer[0][i]=x[0][j];//position in next line = info from this line
			i++;
			j++;
		}
			int n = 0;
			while(transfer[0][n] != '\0'){
			stringForPath+=transfer[0][n];
			n++;
			}
			paths.push_front(stringForPath);
			numberOfLines++; //increment number of lines
				counter2++;
	}
	else{
		counter2++;
	}
	}
	}
	while (true)
	{
		if (true)
		{
			cout << goal << endl;
			break;
		}
		
	}
	system("pause");
	return 0;
}