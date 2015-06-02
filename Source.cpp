#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
struct partialPath{
		string path;
		int distanceTraveled;
	};
struct partialPathStar{
		string path;
		int distanceTraveled;
		int distanceFromGoal;
	};
	bool path_sorter(partialPath const& lhs, partialPath const& rhs){
			return lhs.distanceTraveled < rhs.distanceTraveled;	
	}
	bool path_sorterStar(partialPathStar const& lhs, partialPathStar const& rhs){
			return lhs.distanceTraveled < rhs.distanceTraveled;	
	}
	bool path_sorterStarFrom(partialPathStar const& lhs, partialPathStar const& rhs){
			return lhs.distanceFromGoal > rhs.distanceFromGoal;	
	}
int main()
{
	int slength = 0, glength = 0, counter2 = 0, numberOfLines = 0, stringPosition = 0;
	string input, goal, inputStar;
	partialPath stringForPath, in; 
	partialPathStar inStar, stringForPathStar;
	bool valid = false, movePerformed = false, goalAttained = false;
	while (valid != true)
	{
		cout << "Input starting string: ";
		cin >> input;
		cout << "Input goal string: ";
		cin >> goal;
		inputStar = input;	
		slength = input.size();
		glength = goal.size();
		if (glength != slength)
		{
			cout << "Strings are not same length. Re-input strings." << endl;
		}
		else
			valid = true;
		}
	char x[1][1000] , transfer[1][1000], test[1000];
	deque<partialPath> paths;
		for (int j = 0; j < 1000; j++)//set entire char array to null
		{
			x[0][j] = '\0';
		}
	for (int j = 0; j < 1000; j++)//set entire char array to null
		{
			transfer[0][j] = '\0';
		}
	strcpy_s(x[0], input.c_str());
	in.path = input;
	in.distanceTraveled = 0;
	paths.push_front(in);
	stringForPath.distanceTraveled = 0;

	//BRANCH AND BOUND



	while(goalAttained == false){//while goal not attained
		while(counter2 < slength){ //run as many times as string is long
for (int j = 0; j < 1000; j++)//check to see it goal is reached
   {
    test[j] =x[0][j];
   }
   string tst(test);
   if (tst.substr(0,glength)==goal)
   {
    cout <<"Answer according to Branch and Bound: "<< tst << endl;
	goalAttained = true;
	counter2 += slength+1;
   }		
	if(x[0][counter2] == '(' || x[0][counter2] == '-'){ //Move left if hit (
		counter2++;
	}
	else if(x[0][counter2] == ')'){ //Move to next string when done with current string  ALL CHILDREN BORN: NOW SORT
		paths.pop_back();
		//SORT QUEUE BY .distanceTraveled
		sort(paths.begin(), paths.end(), &path_sorter);//sort by distance traveled
		//SORT ABOVE
		stringPosition++;//increment position in string array
		counter2 = 0;
		input = paths.back().path;//set input to next string 
		strcpy_s(x[0], input.c_str());//set x[0] to input (the next srting)
	}
	else if(x[0][counter2+1] == '-'){  //if position to the right is -	
		stringForPath = paths.back();
		stringForPath.path.erase();	
		for(int i = 0;i<1000;i++){
			transfer[0][i]=0;  //clear out transfer
		}
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
			stringForPath.path+=transfer[0][n];
			n++;
			}
				stringForPath.distanceTraveled+=1;//increment distance
			paths.push_front(stringForPath);
				numberOfLines++; //REMOVE AT THE END, THIS TRACKS PARENT COUNT FOR DEBUGGING
					counter2++;
	}
	else if(x[0][counter2+2] == '-'){  //if position to the right is -
		stringForPath = paths.back();
		stringForPath.path.erase();		
		for(int i = 0;i<1000;i++){
			transfer[0][i]=0;  //clear out transfer
		}
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
			while(transfer[0][n] != '\0'){//move rest of string to new line
			stringForPath.path+=transfer[0][n];
			n++;
			}
			stringForPath.distanceTraveled+=1;//increment distance
			paths.push_front(stringForPath);
			numberOfLines++; //increment number of lines
				counter2++;//next char
	}
	else{
		counter2++;//next char
	}
	}
	}

	
	//A*


	//Spaces * number of chars = # of steps worst case scenario if chars# = '-'# then that = slength - 2 * slength - 1
	int estimate = ((slength - 2) / 2) * ((slength - 2)/ 2);
	int compareCounter = 0;
	goalAttained = false;
	counter2 = 0;
	inStar.path = inputStar;
	inStar.distanceTraveled = 0;
	inStar.distanceFromGoal = estimate;
	deque<partialPathStar> pathsStar;
	deque<partialPathStar> pathsStarCompare;
	deque<partialPathStar> pathsStarCompareHolder;
	char pathsStarCompareFromList[1][1000];
	char pathsStarCompareNewParent[1][1000];
		for (int j = 0; j < 1000; j++)//set entire char array to null
		{
			pathsStarCompareNewParent[0][j] = '\0';
		}
			for (int j = 0; j < 1000; j++)//set entire char array to null
		{
			pathsStarCompareFromList[0][j] = '\0';
		}
		for (int j = 0; j < 1000; j++)//set entire char array to null
		{
			x[0][j] = '\0';
		}
	for (int j = 0; j < 1000; j++)//set entire char array to null
		{
			transfer[0][j] = '\0';
		}
	strcpy_s(x[0], inputStar.c_str());
	pathsStar.push_front(inStar);
	stringForPathStar.distanceTraveled = 0;
	stringForPathStar.distanceFromGoal = estimate;

		while(goalAttained == false){//while goal not attained
		while(counter2 < slength){ //run as many times as string is long
for (int j = 0; j < 1000; j++)//check to see it goal is reached
   {
    test[j] =x[0][j];
   }
   string tstStar(test);
   if (tstStar.substr(0,glength)==goal)
   {
    cout <<"Answer according to A*: "<< tstStar << endl;
    system("pause");
    return 0;
   }		
	if(x[0][counter2] == '(' || x[0][counter2] == '-'){ //Move left if hit (
		counter2++;
	}
	else if(x[0][counter2] == ')'){ //Move to next string when done with current string  ALL CHILDREN BORN: NOW SORT
		compareCounter = 0;
		pathsStarCompare.push_back(pathsStar.back());//Pust this parent into compare queue
		pathsStar.pop_back();//Kill the Parent
		//SORT QUEUE BY .distanceFromGoal (estimated)
		sort(pathsStar.begin(), pathsStar.end(), &path_sorterStarFrom);//Sort by estimated distance to goal
		//SORT ABOVE
		stringPosition++;//REMOVE AT THE END, THIS TRACKS PARENT COUNT FOR DEBUGGING
		counter2 = 0;
		inputStar = pathsStar.back().path;//set input to next string 
		strcpy_s(pathsStarCompareNewParent[0], inputStar.c_str());//set pathsStarNewParent[0] to inputStar (the next srting)
		
		
		while(!pathsStarCompare.empty()){



			compareCounter = 0;
	strcpy_s(pathsStarCompareFromList[0], pathsStarCompare.back().path.c_str());//set pathsStarCompareFromList[0] to pathsStar string from list
	pathsStarCompareHolder.push_front(pathsStarCompare.back());//push back of compare into top of holder
	pathsStarCompare.pop_back();//remove parent from compare




			for(int t = 0;t<slength;t++){
				if(pathsStarCompareNewParent[0][t] == pathsStarCompareFromList[0][t])//compare
				{
					compareCounter++;//if = slength then match
				}
			}




		if(compareCounter == slength)//if match
		{
		/*strcpy_s(pathsStarCompareFromList[0], pathsStarCompare.back().path.c_str());//set pathsStarCompareFromList[0] to pathsStar string from list
		pathsStarCompareHolder.push_front(pathsStarCompare.back());//push back of compare into top of holder
	    pathsStarCompare.pop_back();//remove parent from compare
		*/
		pathsStar.pop_back();
		inputStar = pathsStar.back().path;//set input to next string 
		strcpy_s(pathsStarCompareNewParent[0], inputStar.c_str());//set pathsStarNewParent[0] to inputStar (the next srting)
		while(!pathsStarCompareHolder.empty()){
			pathsStarCompare.push_back(pathsStarCompareHolder.front());//push the front of holder into the back of compare
			pathsStarCompareHolder.pop_front();
		}
		}





		}





		while(!pathsStarCompareHolder.empty()){
			pathsStarCompare.push_back(pathsStarCompareHolder.front());
			pathsStarCompareHolder.pop_front();
		}
		strcpy_s(x[0], inputStar.c_str());//set x[0] to input (the next srting)
	}
	else if(x[0][counter2+1] == '-'){  //if position to the right is -	
		stringForPathStar = pathsStar.back();
		stringForPathStar.path.erase();	
		for(int i = 0;i<1000;i++){
			transfer[0][i]=0;  //clear out transfer
		}
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
			stringForPathStar.path+=transfer[0][n];
			n++;
			}
				stringForPathStar.distanceFromGoal-=1;//decrement estimated distance to goal
			pathsStar.push_front(stringForPathStar);
				numberOfLines++; //increment number of lines
					counter2++;
	}
	else if(x[0][counter2+2] == '-'){  //if position to the right is -
		stringForPathStar = pathsStar.back();
		stringForPathStar.path.erase();		
		for(int i = 0;i<1000;i++){
			transfer[0][i]=0;  //clear out transfer
		}
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
			while(transfer[0][n] != '\0'){//move rest of string to new line
			stringForPathStar.path+=transfer[0][n];
			n++;
			}
			stringForPathStar.distanceFromGoal-=2;//decrement estimated distance to goal
			pathsStar.push_front(stringForPathStar);
			numberOfLines++; //increment number of lines
				counter2++;//next char
	}
	else{
		counter2++;//next char
	}
	}
	}

	system("pause");
	return 0;
}