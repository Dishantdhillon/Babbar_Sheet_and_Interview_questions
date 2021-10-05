#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;

long long net = 0;
vector<pair<pair<int, int>, int>> R;
vector<pair<pair<int, int>, int>> R2;

// .first.first -> start time
// .first.second -> speed
// .second -> identity

bool mine[maxN+1];

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if(a.first.first > b.first.first)
    {
        return true;
    }
    else if(a.first.first < b.first.first)
    {
        return false;
    }
    else
    {
        if(a.first.second > b.first.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void compute(int beg, int end)
{
    if(end-beg <= 1)
    {
        return;
    }
    
    int mid = (beg+end)/2;
    
    compute(beg, mid);
    compute(mid, end);
    
    R2.clear();
    int i = beg, j = mid;
    
    int count1 = 0, count2 = 0;
    while(i != mid or j != end)
    {
        if(i == mid)
        {
            R2.push_back(R[j++]);
        }
        else if(j == end)
        {
            if(mine[R[i].second])
            {
                net += count1;
            }
            net -= count2;
            
            R2.push_back(R[i++]);
        }
        else
        {
            if(R[i].first.second <= R[j].first.second)
            {
                if(mine[R[i].second])
                {
                    net += count1;
                }
                net -= count2;
                
                R2.push_back(R[i++]);
            }
            else
            {
                if(mine[R[j].second])
                {
                    count2++;
                }
                count1++;
                
                R2.push_back(R[j++]);
            }
        }
    }
    
    for(int i=0; i<R2.size(); i++)
    {
        R[beg+i] = R2[i];
    }
}

int main()
{
    int N, K;
    cin >> N >> K;
    
    R.resize(N);
    
    for(int i=0; i<K; i++)
    {
        int k;
        cin >> k;
        
        mine[k] = true;
    }
    
    for(int i=0; i<N; i++)
    {
        int t, v;
        cin >> t >> v;
        
        R[i] = make_pair(make_pair(t, v), i+1);
    }
    
    sort(R.begin(), R.end(), cmp);
    for(int i=0; i<N; i++)
    {
        cout << R[i].first.first << " " << R[i].first.second << " " << R[i].second << "\n";
    }
    compute(0, N);
    
    cout << net << "\n";
}