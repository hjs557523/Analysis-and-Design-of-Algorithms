#define MAX 99999.99
Double ClosetestDistanceDotPair(double A[],int start,int end){
	if (start - end <= 0)
		return MAX;
	else if (end == start + 1)
		return A[end]-A[start];
	else {
		int mid = (start + end)/2;
		double x = ClosetestDistanceDotPair(A,start,mid);
		double y = ClosetestDistanceDotPair(A,mid+1,end);
		double z = A[mid+1] - A[mid];
		double temp1 = min(x,y);
		double result = min(temp1,z); 
		return result;
	}
}
