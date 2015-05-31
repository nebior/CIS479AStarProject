#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main()
{

	int slength = 0, glength = 0, counter1 = 0, counter2 = 0, numberOfLines = 0;
	string input, goal;
	bool valid = false, movePerformed = false, goalAttained = false;
	while (valid != true)
	{
		cout << "Input starting string: ";
		cin >> input;
		cout << "Input goal string: ";
		cin >> goal;
		char goalArray[1013];
		
		slength = input.size();
		glength = goal.size();
		if (slength != glength)
		{
			cout << "Strings are not same length. Re-input strings." << endl;
		}
		else
			valid = true;
	}
	char x[1000][1000] , temp[1][1000], test[1000];
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			x[i][j] = '\0';
		}
	}
	strcpy_s(x[0], input.c_str());
	while(goalAttained == false){
		while(counter2 < slength){
			if(numberOfLines+1 == 1000){
				for(int j = 0; j<1000; j++){
				x[0][j]=x[999][j];
				}
				numberOfLines = 0;
				counter1= 0;
				counter2 = 0;
			}

for (int j = 0; j < 1000; j++)
   {
    test[j] =x[counter1][j];
   }
   string tst(test);
   if (tst.substr(0,glength)==goal)
   {
    cout << tst << endl;
    system("pause");
    return 0;
   }
			
	if(x[counter1][counter2] == '(' || x[counter1][counter2] == '-'){ //Move left if hit (
		counter2++;
	}
	else if(x[counter1][counter2] == ')'){ //Move to next line when done with first string in line
		counter1++;
		counter2 = 0;
	}
	else if(x[counter1][counter2+1] == '-'){  //if position to the right is -
		for(int i = 0;i<slength;i++){
			x[numberOfLines+1][i]=x[counter1][i];  //write newest path to next line
		}
		x[numberOfLines+1][counter2+1]=x[counter1][counter2];//in new line move char to -
		x[numberOfLines+1][counter2] = '-';//in new line put - where char was	
			int i = slength; //start writing after length of next line
			int j=0; //new counter
			while(x[counter1][j] != '\0'){ //until end of current line
			x[numberOfLines+1][i]=x[counter1][j];//position in next line = info from this line
			i++;
			j++;
		}	
				numberOfLines++; //increment number of lines
					counter2++;
	}
	else if(x[counter1][counter2+2] == '-'){  //if position to the right is -
		for(int i = 0;i<slength;i++){
			x[numberOfLines+1][i]=x[counter1][i];  //write newest path to next line
		}
		x[numberOfLines+1][counter2+2]=x[counter1][counter2];//in new line move char to -
		x[numberOfLines+1][counter2] = '-';//in new line put - where char was	
			int i = slength; //start writing after length of next line
			int j=0; //new counter
			while(x[counter1][j] != '\0'){ //until end of current line
			x[numberOfLines+1][i]=x[counter1][j];//position in next line = info from this line
			i++;
			j++;
		}
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