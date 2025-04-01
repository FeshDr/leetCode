// задача интерактивная, тоэтому прям прогнать не получиться

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

 class Solution {
    public:
        int findInMountainArray(int target, MountainArray &mountainArr) {
            int arrLen = mountainArr.length();
            int left = mountainArr.get(0);
            int right = mountainArr.get(arrLen-1);
    
            if(target == left) return 0;
            //if(target == right) return arrLen-1 ;
    
            std::pair<int,int> midDot = findMid(left,right,0,arrLen-1,mountainArr);
    
            //return midDot.first;
    
            if(midDot.first == -1) {
                midDot.first = ((arrLen-1)/2);
                midDot.second = mountainArr.get((arrLen-1)/2);
            }
    
            
            if(target == midDot.second) return midDot.first;
    
    
           
            int resL = leftSearch(left,midDot.second,0,midDot.first,mountainArr,target);
            int resR = rightSearch(midDot.second,right,midDot.first,arrLen-1,mountainArr,target);
    
            if(resL == -1) return resR;
            if(resR == -1) return resL;
    
            if(resL < resR) {
                return resL;
            } else {
                return resR;
            }
    
        }
    
        //1
        std::pair<int,int> findMid(int left, int right, int leftInd, int rightInd, MountainArray &mountainArr) {
    
            std::cout << (leftInd+rightInd)/2 - 1 << "<" << (leftInd+rightInd)/2 << ">" << (leftInd+rightInd)/2 + 1 << "\n";
    
            if(rightInd-leftInd < 2){
                 return make_pair(-1,-1);
            }
    
            int mid = mountainArr.get((leftInd+rightInd)/2);
            int midL = mountainArr.get((leftInd+rightInd)/2 - 1);
            int midR = mountainArr.get((leftInd+rightInd)/2 + 1);
    
            std::pair<int,int> currMid = {(leftInd+rightInd)/2, mid};
    
            std::cout << midL << "<" << mid << ">" << midR << " , MidInd == " << (leftInd+rightInd)/2 << "\n";
    
            if((midL < mid) && (mid > midR)) { // pik
    
                return currMid;
    
            } else if((midL < mid) && (mid < midR)) {
    
                std::pair<int,int> childR = findMid(mid,right,(leftInd+rightInd)/2,rightInd,mountainArr);
                if(childR.second > currMid.second) return childR;
    
            } else {
    
                std::pair<int,int> childL = findMid(left,mid,leftInd,(leftInd+rightInd)/2,mountainArr);
                if(childL.second > currMid.second) return childL;
    
            }
    
            return make_pair(-1,-1);
        }
    
        int leftSearch(int left, int right, int leftInd, int rightInd, MountainArray &mountainArr, int t) {
            if(rightInd-leftInd < 2){
                if (t == left) return leftInd;
                if(t == right) return rightInd;
                return -1;
            }
            int mid = mountainArr.get((leftInd+rightInd)/2);
            if(mid == t) return (leftInd+rightInd)/2;
    
            if(t > mid){
                return leftSearch(mid, right,(leftInd+rightInd)/2, rightInd,mountainArr,t);
            } else {
                return leftSearch(left, mid,leftInd,(leftInd+rightInd)/2,mountainArr,t);
            }
        }
    
        int rightSearch(int left, int right, int leftInd, int rightInd, MountainArray &mountainArr, int t) {
            if(rightInd-leftInd < 2){
                if (t == left) return leftInd;
                if(t == right) return rightInd;
                return -1;
            }
            int mid = mountainArr.get((leftInd+rightInd)/2);
            if(mid == t) return (leftInd+rightInd)/2;
    
            if(t < mid){
                return rightSearch(mid, right,(leftInd+rightInd)/2, rightInd,mountainArr,t);
            } else {
                return rightSearch(left, mid,leftInd,(leftInd+rightInd)/2,mountainArr,t);
            }
        }
    
    };