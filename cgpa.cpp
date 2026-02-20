#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

 float grading(char grade){
	
switch(grade)
	{
		case 'A':
			return 4.0;
			case 'B':
			return 3.0;
			case 'C':
			return 2.0;
			case 'D':
			return 1.0;
			case 'F':
			return 0.0;
			default:
				cout<<"invalid grade!";
	}
}
int main()
{
	int courses;
	cout<<"Enter number of courses: ";
	cin>>courses;
  vector<char>grades(courses);
vector<float>credits(courses);
float totalcredits=0;
float gradepoints=0;
//taking input 
for(int i=0;i<courses;i++)
{
	
	cout<<"course "<<i+1<<endl;
	cout<<"Enter Credithours: ";
	
	cin>>credits[i];
	
	cout<<"Enter grades : ";
	cin>>grades[i];
	totalcredits+=credits[i];
	gradepoints+=grading(grades[i])*credits[i];
	
}
float GPA=gradepoints/totalcredits;
float CGPA=GPA;

//for display 
cout<<"        "<<endl;
cout<<"        "<<endl;

cout<<"------Course detail------"<<endl;
for(int i=0;i<courses;i++)
{
	
	cout<<"course "<<i+1<<"| Credithours: "<<credits[i]<<"|Grades: "<<grades[i]<<endl;
	}
	cout<<"Total credithours: "<<totalcredits<<endl;
	cout<<fixed<<setprecision(2);
	cout<<"Total CGPA: "<<CGPA<<endl;

return 0;
	
}
