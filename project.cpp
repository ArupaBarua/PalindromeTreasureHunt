#include<bits/stdc++.h>
using namespace std;
vector<char> clue({'A', 'E', 'S', 'B', 'N', 'W', 'D', 'A', 'A', 'E', 'S', 'E'});
int cnt_clue;
class passcheck
{
public:
    static int flag, cnt, Move;
    char check(string p, char roomnum)
    {
        string s;
        int i;
        if(p.size() == 9){
            set<char>occur;
            for(i = 0; i < 9; ++i){
                occur.insert(p[i]);
            }
            for(auto val : occur){
                if(val == '1' || val == '2' || val == '3' || val == '4' || val == '5'){
                    continue;
                }
                else{
                    Move--;
                    if(Move == 0){
                        cout << "Game Over! You lost all of your moves!";
                        return '-1';
                    }
                    else{
                        cout << "Wrong key! ";
                        cout << "You have " << Move << " " << "moves left" << endl;
                        return '0';
                    }
                }
            }
        }
        if(cnt == 0){
            s = p;
            reverse(s.begin(), s.end());
            if(s != p || p.size() != 9 || p[0] != '1'){
                Move--;
                cout << "Wrong key! ";
                cout << "You have " << Move << " " << "moves left" << endl;
                return '0';
            }
            if(p[4] == '5'){
                return p[4];
            }
            cnt++;
            cout << "\a";
            cout << "You unlocked the clue box and door of room " << p[4] << "!" << endl;
            return p[4];
        }
        s = p;
        reverse(s.begin(), s.end());
        if(s == p && p.size() == 9){
            if(p[0] != roomnum){
                Move--;
                if(Move == 0){
                    cout << "Game Over! You lost all of your moves!";
                    return '-1';
                }
                else{
                    cout << "Wrong key! ";
                    cout << "You have " << Move << " " << "moves left" << endl;
                    return '0';
                }
            }
            if(p[4] == '5' && cnt_clue < 3){
                return p[4];
            }
            cout << "\a";
            cout << "You unlocked the clue box and door of room " << p[4] << "!" << endl;
            return p[4];
        }
        else{
            Move--;
            if(Move == 0){
                cout << "Game Over! You lost all of your moves!";
                return '-1';
            }
            else{
                cout << "Wrong key! ";
                cout << "You have " << Move << " " << "moves left" << endl;
                return '0';
            }
        }
    }
};
class room1 : public passcheck
{
public:
    string pass;
    char ch;
    virtual char cluepass()
    {
        cout << "You are in the 1st room now. Unlock the first clue box and get your clue." << endl;
        cin >> pass;
        ch = check(pass, '1');
        if(ch != '-1' && ch != '0'){
            if((ch == '5' && cnt_clue < 3) == 0){
                cout << "Take the letter " << clue[0] << endl;
                cnt_clue++;
            }
        }
        return ch;
    }
};
class room2 : public room1
{
public:
    char cluepass()
    {
        cout << "You are in the 2nd room now. Unlock the second clue box and get your clue." << endl;
        cin >> pass;
        ch = check(pass, '2');
        if(ch != '-1' && ch != '0'){
            if((ch == '5' && cnt_clue < 3) == 0){
                cout << "Take the letter " << clue[1] << endl;
                cnt_clue++;
            }
        }
        return ch;
    }
};
class room3 : public room1
{
    char cluepass()
    {
        cout << "You are in the 3rd room now. Unlock the third clue box and get your clue." << endl;
        cin >> pass;
        ch = check(pass, '3');
        if(ch != '-1' && ch != '0'){
            if((ch == '5' && cnt_clue < 3) == 0){
                cout << "Take the letter " << clue[2] << endl;
                cnt_clue++;
            }
        }
        return ch;
    }
};
class room4 : public room1
{
    char cluepass()
    {
        cout << "You are in the 4th room now. Unlock the fourth clue box and get your clue." << endl;
        cin >> pass;
        ch = check(pass, '4');
        if(ch != '-1' && ch != '0'){
            if((ch == '5' && cnt_clue < 3) == 0){
                cout << "Take the letter " << clue[3] << endl;
                cnt_clue++;
            }
        }
        return ch;
    }
};
class room5 : public passcheck
{
public:
    bool reach = false;
    int countt = 1;
    room5()
    {
        string tressure_key, ans;
        vector<string> final_key({"BASE", "DAWN", "EASE"});
        cout << "You are in the tressure room now!" << endl;
        cout << "To unlock the tressure you have to form a meaningful word with the clue letters" << endl;
        cout << "Remember there is only one meaningful word form possible. ";
        cout << "All the best!";
        label:
        cin >> tressure_key;
        if(tressure_key == final_key[0]){
            cout << "Congratulations! You unlocked the tressure box!" << endl << endl;
            cout << "Would you like to play the game again?";
            cin >> ans;
            if(ans == "yes"){
                if(countt == 3){
                    cout << "Sorry you cannot play the game more than thrice." << endl;
                }
                else{
                    countt++;
                    clue.erase(clue.begin(), clue.begin()+4);
                    final_key.erase(final_key.begin(), final_key.begin()+1);
                    Move = 0;
                    cnt = 0;
                    flag = 1;
                    reach = true;
                }
            }
        }
        else{
            Move--;
            if(Move == 0){
                cout << "Wrong Word! " << "Game Over!";
            }
            else{
                cout << "Wrong Word! " << "You have " << Move << "moves left.";
                goto label;
            }
        }
    }
};
int passcheck::cnt;
int passcheck::Move = 3;
int passcheck::flag = 1;
int main()
{
    cout << "                                          Welcome to Find The Tressure!" << endl;
    cout << " Unlock the four clue boxes, get your clues and try to open the tressure." << endl;
    cout << " The clue boxes will open with a nine digit palindrome password." << endl;
    cout << " Remember, every password's first and last digit represent the room number." << endl;
    cout << " And it consists of numbers 1,2,3,4 and 5 where every digit appears twice except the room you are trying to open." << endl;
    cout << "The tressure is in the fifth room.";
    cout << " Let's go!" << endl;
    start:
    room1 *ara[6];
    room1 r1;
    room2 r2;
    room3 r3;
    room4 r4;
    ara[1] = &r1;
    ara[2] = &r2;
    ara[3] = &r3;
    ara[4] = &r4;
    char ch = ara[1]->cluepass();
    string s(1, ch);
    int num = stoi(s);
    int store = 1;
    while(1){
        if(cnt_clue == 4)
            break;
        if(num == 5 && cnt_clue < 4){
            cout << "You cannot open the fifth room until you have all the clues." << endl;
            ch = ara[store]->cluepass();
            string s(1, ch);
            num = stoi(s);
        }
        else if(num == 0){
            ch = ara[store]->cluepass();
            string s(1, ch);
            num = stoi(s);
        }
        else if(num == -1){
            return 0;
        }
        else{
            ch = ara[num]->cluepass();
            if(ch == '0' || (ch == '5' && cnt_clue < 3)){
               store = num;
            }
            string s(1, ch);
            num = stoi(s);
        }
    }
    if(cnt_clue == 4){
        room5 r5;
        bool b = r5.reach;
        if(b){
            goto start;
        }
    }
    return 0;
}
