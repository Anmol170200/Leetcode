typedef pair<int, int> pii;
typedef map< pii, int> ump;

class Solution {
    
public:
    
    void moveNorth( int& x, int& y, int& v, ump& mp ){
        while( v-- ){
            int y2 = y+1;
            if( mp.count({x, y2}) ){
                return;
            }
            y = y2;
        }
    }
    
    void moveSouth( int& x, int& y, int& v, ump& mp ){
        while( v-- ){
            int y2 = y-1;
            if( mp.count({x, y2}) ){
                return;
            }
            y = y2;
        }
    }
    
    void moveEast( int& x, int& y, int& v, ump& mp ){
        while( v-- ){
            int x2 = x+1;
            if( mp.count({x2, y}) ){
                return;
            }
            x = x2;
        }
    }
    
    void moveWest( int& x, int& y, int& v, ump& mp ){
        while( v-- ){
            int x2 = x-1;
            if( mp.count({x2, y}) ){
                return;
            }
            x = x2;
        }
    }
    
    void direction( int& x, int& y, int& v, char& dir, ump& mp ){
        if( dir == 'N' ){
            moveNorth(x, y, v, mp);
        }
        else if( dir == 'S' ){
            moveSouth(x, y, v, mp);
        }
        else if( dir == 'E' ){
            moveEast(x, y, v, mp);
        }
        else if( dir == 'W' ){
            moveWest(x, y, v, mp);
        }
        return;
    }
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map< char, char > left;
        unordered_map< char, char > right;
        ump mp;
        
        left['N'] = 'W';
        left['W'] = 'S';
        left['S'] = 'E';
        left['E'] = 'N';
        
        right['N'] = 'E';
        right['E'] = 'S';
        right['S'] = 'W';
        right['W'] = 'N';
        
        char dir = 'N';
        int x = 0, y = 0, ans=0;
        
        for( int i = 0 ; i < obstacles.size() ; i++ ){
            int u = obstacles[i][0], v = obstacles[i][1];
            mp[{u,v}]++;
        }
        
        for( auto i : commands ){
            ans = max( ans, (x*x) + (y*y) );
            if( i == -2 ){
                dir = left[dir];
            }
            else if( i == -1 ){
                dir = right[dir];
            }
            else{
                direction( x, y, i, dir, mp );
            }
        }
        
        ans = max( ans, (x*x) + (y*y));
        return ans;
        
    }
};