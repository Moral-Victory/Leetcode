class MedianFinder {
public:
    priority_queue<double> left;
    priority_queue<double, vector<double>, greater<double>> right;
    vector<double> temp;

    MedianFinder() {
        // MedianFinder medianFinder = new MedianFinder();
    }
    
    void addNum(int num) {
        // temp.push_back(num);
        // sort(temp.begin(),temp.end());

        if(left.empty()||left.top()>=num){
            left.push(num);
        }
        else if(left.top()<num){
            right.push(num);
        }

        if(left.size()>1+right.size()){
            right.push(left.top());
            left.pop();
        }
        else if(right.size()>left.size()){
            left.push(right.top());
            right.pop();
        }


    }
    
    double findMedian() {
        // int n=temp.size();
        // if(n%2==0){
        //     return (temp[n/2] + temp[n/2-1])/2.0;
        // }
        // else{
        //     return temp[n/2];
        // }

        if(left.size()==right.size()){
            return (double(left.top()+right.top())/2.0);
        }
        else{
            return left.top();
        }


    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */