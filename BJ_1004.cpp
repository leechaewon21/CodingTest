
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


// PLANET CLASS
class Circle {
	public:
		int x;
		int y;
		int r;
		int in_point;

		void setCircle(int _x,int _y, int _r) {
			x = _x;
			y = _y;
			r = _r;
			in_point = 0;
		}
};

// GET DISTANCE BETWEEN POINT1 AND POINT2
float distance(int px1, int py1, int px2, int py2) {
	return sqrt(pow(px1-px2,2)+pow(py1-py2,2));
}

// FIND PLANET WHICH HAS ONLY ONE POINT
int solve(vector<Circle> &circles, pair<int,int> start, pair<int,int> end, int cn) {
	//PLANETS, START POINT, END POINT, PLANET COUNT

	int answer = 0;

	for(int i=0; i<cn; i++) {
		//START POINT IN CHECK
		if(distance(circles[i].x,circles[i].y,start.first,start.second) <= circles[i].r) {
			circles[i].in_point++;
		}
		//END POINT IN CHECK
		if(distance(circles[i].x,circles[i].y,end.first,end.second) <= circles[i].r) {
			circles[i].in_point++;
		}
	}

    	// UPDATE ENTER(ESCAPE) COUNT
	for(int i=0; i<cn; i++){
		if(circles[i].in_point == 1) answer++;
	}

	return answer;
}

int main() {
    	//TESTCASES ANSWER
	vector<int> answer;

	//INPUT - TESTCASE
	int tc;
	cin >> tc;

	for(int i=0; i<tc; i++) {

		pair<int,int> start, end;
		vector<Circle> circles;

        	// INPUT - START POINT, END POINT
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		start = make_pair(x1,y1);
		end = make_pair(x2,y2);

		// INPUT - PLANET COUNT
		int cn;
		cin >> cn;

		// INPUT - PLANET
		for(int j=0; j<cn; j++) {
			int x,y,r;
			cin >> x >> y >> r;

			Circle c;
			c.setCircle(x,y,r);

			circles.push_back(c);
		}

		// TESTCASE'S SOLVE
		int ans = solve(circles,start,end,cn);
		answer.push_back(ans);
	}

	// OUTPUT - TESTCASES ANSWER
	for(int ans:answer) cout << ans << endl;
	return 0;
}
