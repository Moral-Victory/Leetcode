class Solution {
public:
    vector<vector<int>> sq;
    double areaBelow(double Y, vector<vector<int>>& squares) {
        double s = 0;
        for (auto& sq : squares) {
            double y = sq[1];
            double l = sq[2];
            if (Y <= y) {
                s+=0;
            } else if (Y >= y + l) {
                s += l * l;
            } else {
                s += l * (Y - y);
            }
        }
        return s;
    }
    // double areaAbove(double Y) {
    //     double s = 0;
    //     for (auto &sq : this->sq) {
    //         double y = sq[1];
    //         double l = sq[2];
    //         if (Y <= y) {
    //             s+=l*l;
    //         } else if (Y >= y + l) {
    //             s += 0;
    //         } else {
    //             s += l * (y + - Y);
    //         }
    //     }
    //     return s;
    // }


    double separateSquares(vector<vector<int>>& squares) {
        // this->sq = squares;
        double lo = INT_MAX; 
        double hi = INT_MIN;
        double total = 0;
        for (auto &sq : squares) {
            double y = sq[1];
            double l = sq[2];
            lo = min(lo, y);
            hi = max(hi, y + l);
            total += l * l;
        }
        double target=total/2.0;

        while(hi-lo>1e-5) {
            double mid = (lo + hi) / 2.0;
            if (areaBelow(mid, squares) < target)
                lo = mid;
            else
                hi = mid;
        }

        return (lo + hi) / 2.0;
        
    }
};