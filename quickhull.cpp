#include<bits/stdc++.h>
	using namespace std;
	
	struct point{	int x,y;
	};
	vector<point> answer;
	int dir( point p, point q, point r ){
	int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
     if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
int dot_product(int A[], int B[], int C[]){
	        int AB[2], BC[2];
	        AB[0] = B[0]-A[0];
	        AB[1] = B[1]-A[1];
	        BC[0] = C[0]-B[0];
	        BC[1] = C[1]-B[1];
	        int dot = AB[0] * BC[0] + AB[1] * BC[1];
	        return dot;
	    }
	
	    int cross_product(int A[], int B[], int C[]){
	        int AB[2],AC[2];
	        AB[0] = B[0]-A[0];
	        AB[1] = B[1]-A[1];
	        AC[0] = C[0]-A[0];
	        AC[1] = C[1]-A[1];
	        int cross = AB[0] * AC[1] - AB[1] * AC[0];
	        return cross;
	    }
	
	    double dist(int A[], int B[]){
	        int d1 = A[0] - B[0];
	        int d2 = A[1] - B[1];
	        return sqrt(d1*d1+d2*d2);
	    }
	    double linePointDist(int A[], int B[], int C[]){
	            int dot1 = dot_product(A,B,C);
	            if(dot1 > 0)return dist(B,C);
	            int dot2 = dot_product(B,A,C);
	            if(dot2 > 0)return dist(A,C);
	       }
	double line_to_point_distance(point A, point B, point C){
	        	double dist = ((B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x)) / sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
	            int dot1 = (C.x-B.x)*(B.x-A.x)+(C.y-B.y)*(B.y-A.y);
	            if(dot1 > 0)return sqrt((B.x-C.x)*(B.x-C.x)+(B.y-C.y)*(B.y-C.y));
	            int dot2 = (C.x-A.x)*(A.x-B.x)+(C.y-A.y)*(A.y-B.y);
	            if(dot2 > 0)return sqrt((A.x-C.x)*(A.x-C.x)+(A.y-C.y)*(A.y-C.y));
	        return abs(dist);
	    }
	void Find_hull(vector<point> Sk,point A,point B){
		if(Sk.size()==0)
		return;
		int maxi=line_to_point_distance(A,B,Sk[0]);
		int C=0;
		for(int i=0;i<Sk.size();i++){
			if(line_to_point_distance(A,B,Sk[i])>maxi){
				maxi=line_to_point_distance(A,B,Sk[i]);
				C=i;
			}
		}
		answer.push_back(Sk[C]);
		vector<point> S1,S2;
		for (int i=0;i<Sk.size();i++){
			if( dir(A,Sk[C],Sk[i])==1){
				S1.push_back(Sk[i]);
			}
			if( dir(Sk[C],B,Sk[i])==1){
				S2.push_back(Sk[i]);
			}
		}
		Find_hull(S1,A,Sk[C]);
		Find_hull(S2,Sk[C],B);
		}
	vector<point> QuickHull( point array[], int n){
	if (n<3){
			return answer;
		}
	int leftmostpoint=array[0].x;
		int min_i=0;
		for( int i=0;i<n;i++){
			if( array[i].x < leftmostpoint )
			{
				min_i=i;
				leftmostpoint= array[i].x;
			}
		}
		point A = array[min_i];
		int rightmostpoint=array[0].x;
		min_i=0;
		for( int i=0;i<n;i++){
			if( array[i].x > rightmostpoint )
			{
				min_i=i;
				rightmostpoint= array[i].x;
			}
		}	
		point B = array[min_i];
		
		answer.push_back(A);
		answer.push_back(B);
		
		vector<point> S1,S2;
		for (int i=0;i<n;i++){
			// find points in right of A->B
			if( dir(A,B,array[i])==1){
				S1.push_back(array[i]);
			}
			// find points in right of B->A
			if( dir(B,A,array[i])==1){
				S2.push_back(array[i]);
			}
		}
		
		
		Find_hull(S1,A,B);
		Find_hull(S2,B,A);
		
		return answer;
		
	}
	int dist( point p, point q){
		
		int distance= (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
		return distance;
	}
	

	point p;
	int compare( const void *p1, const void *p2){
		point *x= (point *)p1;
		point *y= (point *)p2;
		
		int ans= dir(p,*x,*y);
		
		if ( ans ==0){
			if ( dist(p,*y)>= dist(p,*x)){
				return -1;
			}
			else return 1;
		}
		
		else if( ans==2){
			return -1;
		}
		
		else
		{
			return 1;
		}
	}
	int main(){
		 point  array[] = {{0, 3}, {2, 2}, {1, 1}, {5, 1}, {3, 0}, {1, 0}, {3, 6}};
		 int n=sizeof(array)/sizeof(array[0]);
		clock_t t1,t2;
	    t1=clock();
		vector<point> answer=QuickHull(array,n);
		p=answer[0];
		qsort(&answer[1], answer.size()-1, sizeof(point),compare);
		t2=clock();
		for ( int i=0;i<answer.size();i++){
			cout<<"( " << answer[i].x << " , " << answer[i].y<< " )"<<endl;
		}
		//time code
		float diff=((float)t2-(float)t1);
		float seconds = diff / CLOCKS_PER_SEC;	
	    cout<<"RUNNNING TIME --> "<<seconds<<endl;
		
	}

