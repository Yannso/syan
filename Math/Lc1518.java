public class Lc1518 {
    /*
    * 换酒瓶问题->   数学
    * https://leetcode-cn.com/problems/water-bottles/
    * */
    public int numWaterBottles(int sum, int k) {
        int ans = 0;
        int mod = 0;
        while (sum + mod >= k){
            //  currently i have cur bottles
            int cur = sum + mod;
            //  i can exchange can bootles
            int can = cur / k;
            //  be able to exchange can bootles means would drink can * k bootles
            ans += can * k;
            //  there are left mod bottles
            mod = cur % k;
            //  there are the new one
            sum = can;
        }
        return ans + sum + mod;
    }
}
