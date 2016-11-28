struct Node { //min cnt jumps to get idx
    var idx: Int = 0
    var cnt: Int = 0
    init(idx: Int, cnt: Int) {
        self.idx = idx
        self.cnt = cnt
    }
}

class Solution {
    func jump(_ nums: [Int]) -> Int {
    
        var dp = [Node]() // a queue which  dp[i+1].idx > dp[i].idx dp[i+1].cnt > dp[i].cnt
        dp.append(Node(idx: 0, cnt:0))
        
        for idx in 0..<nums.count {
            let sta = dp[0]
            if idx > sta.idx {
                dp.remove(at: 0)
            }
            if nums[idx] > 0 {
                let nn = Node(idx: idx + nums[idx], cnt: dp[0].cnt + 1)
                if dp.count < 2 {
                    dp.append(nn)
                } else {
                    // dp[1].cnt == nn.cnt 
                        if (dp[1].idx < nn.idx) {
                            dp[1].idx = nn.idx
                        }
                }
            }
        }
        return dp[0].cnt
    }
}
