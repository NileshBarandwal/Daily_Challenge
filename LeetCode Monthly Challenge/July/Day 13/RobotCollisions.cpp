// 2751. Robot Collisions

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int, int, char, int>> robots; // {position, health, direction, index}
        
        for (int i = 0; i < n; ++i) {
            robots.emplace_back(positions[i], healths[i], directions[i], i);
        }

        // Sort robots by their positions
        sort(robots.begin(), robots.end());

        stack<int> stk; // stack to keep indexes of robots moving to the right
        vector<bool> alive(n, true); // track which robots are alive

        for (const auto& [pos, health, dir, idx] : robots) {
            if (dir == 'R') {
                stk.push(idx);
            } else { // direction == 'L'
                while (!stk.empty() && healths[idx] > 0) {
                    int rIdx = stk.top();
                    if (healths[rIdx] > healths[idx]) {
                        healths[rIdx] -= 1;
                        alive[idx] = false;
                        break;
                    } else if (healths[rIdx] < healths[idx]) {
                        healths[idx] -= 1;
                        alive[rIdx] = false;
                        stk.pop();
                    } else { // healths[rIdx] == healths[idx]
                        alive[rIdx] = false;
                        alive[idx] = false;
                        stk.pop();
                        break;
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (alive[i]) {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};