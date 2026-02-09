class RideSharingSystem {
public:
    queue<int> rider;
    queue<int> driver;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int> res;
        if(driver.empty()||rider.empty()){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
        res.push_back(driver.front());
        res.push_back(rider.front());
        driver.pop();
        rider.pop();
        return res;
    }
    
    void cancelRider(int riderId) {
        vector<int> temp;
        while(!rider.empty()){
            
            int rid=rider.front();
            rider.pop();
            if(rid==riderId){
                continue;
            }
            temp.push_back(rid);
        }
        for(int i:temp){
            rider.push(i);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */