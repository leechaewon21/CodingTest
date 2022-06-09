#include <iostream>
using namespace std;

int countGaro(int arr[][51], int w, int h) {

    int tree_count = 0;
    int before_tree;

    // | => - : COUNT++
    for(int i=0; i<w; i++) {
        int before_tree = 1;
        for(int j=0; j<h; j++) {
            if(before_tree==1 && arr[i][j]==0) tree_count++;
            before_tree = arr[i][j];
        }
    }

    return tree_count;
}

int countSero(int arr[][51], int w, int h) {

    int tree_count = 0;
    int before_tree;

    // - => | : COUNT++
    for(int j=0; j<h; j++) {
        int before_tree = 0;
        for(int i=0; i<w; i++) {
            if(before_tree==0 && arr[i][j]==1) tree_count++;
            before_tree = arr[i][j];
        }
    }

    return tree_count;
}

int main() {
    int deco[51][51];

    //INPUT
    int width, height;
    cin >> width >> height;

    for(int i=0; i<width; i++) {
		string str;
		cin >> str;
		for(int j=0; j<height; j++) {
			if(str[j]=='|') deco[i][j] = 1;
			else deco[i][j]=0;
		}
	}

	int tree_count = 0;

	//TREE COUNT1 (GARO)
	tree_count += countGaro(deco,width,height);
	//TREE COUNT2 (SERO)
	tree_count += countSero(deco,width,height);


	cout <<tree_count<<endl;

    return 0;
}
