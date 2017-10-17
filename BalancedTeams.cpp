//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <algorithm>

using namespace std;
int cow[12], team[4], teamc[4], cteam[4];
int small=1000000000;

void gen(int player)
{
    int i;
    if(player==12){
        for(i=0;i<4;i++)
            cteam[i]=team[i];
        sort(cteam, cteam+4);
        if(cteam[3]-cteam[0]<small)
            small=cteam[3]-cteam[0];
        return;
    }
    for(i=0;i<4;i++){
        if(teamc[i]<3){
            team[i]+=cow[player], teamc[i]++;
            gen(player+1);
            team[i]-=cow[player], teamc[i]--;
        }
    }
}

int main()
{
    int i;
    
    for(i=0;i<12;i++){
        cin >> cow[i];
    }
    gen(0);
    
    cout << small << endl;
    
    return 0;
}
