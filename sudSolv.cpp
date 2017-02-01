#include <iostream>
#include <vector>
using namespace std;

//Solver for a given sudoku puzzle. One example is given in main()
    void solveSudoku(vector<vector<char> >& board) {
        int res;
        bool flag = 0;
        char temp[] = {"123456789"};
        vector<vector<vector<char> > > cand(9,vector<vector<char> >(9,vector<char>(temp,temp + sizeof(temp)/sizeof(char)-1)));
        init(board, cand);
        update(board,cand);
        res = eval(board,cand);
        while(res)
        {
            update(board,cand);
            res = eval(board,cand);

        }

        flag = solved(board);

        if (flag == 0)
        {
            res = update2(board,cand);

            while(res)
            {
                update(board,cand);
                res = update2(board,cand);
    //            cout<<res<<endl;
            }
            flag = solved(board);
            while(flag == 0)
            {
                trial(board,cand);
                res = eval(board,cand);
                while(res)
                {
                    update(board,cand);
                    res = eval(board,cand);
                }
                flag = solved(board);
            }
        }


//display
//        for(i = 0;i<9;i++)
//        {
//            for(j = 0;j<9;j++)
//            {
//                cout<<board[i][j];
//            }
//            cout<<endl;
//        }
//        for(i = 0;i<9;i++)
//        {
//            for(j = 0;j<9;j++)
//            {
//                cout<<"<"<<i<<","<<j<<">";
//                for(k= 0;k<cand[i][j].size();k++)
//                    cout<<cand[i][j][k];
//                cout<<"Size: "<<cand[i][j].size()<<endl;
//            }
//        }
    }

    void init(vector<vector<char> >& board, vector<vector<vector<char> > >& cand)
    {
        int i,j;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                    cand[i][j].erase(cand[i][j].begin(),cand[i][j].end());
            }
        }
    }
    void update(vector<vector<char> >& board, vector<vector<vector<char> > >& cand)
    {
        int i,j,k;
        int r,c;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(r=0;r<9;r++)
                    {
                        for(k=0;k<cand[i][j].size();k++)
                        {
                            if(board[i][r]!='.')
                            {
                                if(board[i][r]==cand[i][j][k])
                                {
                                    cand[i][j].erase(cand[i][j].begin()+k);
                                    k-=1;
                                }
                            }
                        }
                    }
                    for(c=0;c<9;c++)
                    {
                        for(k=0;k<cand[i][j].size();k++)
                        {
                            if(board[c][j]!='.')
                            {
                                if(board[c][j]==cand[i][j][k])
                                {
                                    cand[i][j].erase(cand[i][j].begin()+k);
                                    k-=1;
                                }
                            }
                        }
                    }
                    for(r=(j/3)*3;r<(j/3)*3+3;r++)
                    {
                        for(c=(i/3)*3;c<(i/3)*3+3;c++)
                        {
                            for(k=0;k<cand[i][j].size();k++)
                            {
                                if(board[c][r]!='.')
                                {
                                    if(board[c][r]==cand[i][j][k])
                                    {
                                        cand[i][j].erase(cand[i][j].begin()+k);
                                        k-=1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int update2(vector<vector<char> >& board, vector<vector<vector<char> > >& cand)
    {
        int i,j,k,k0;
        int r,c;
        int res = 0;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(k=0;k<cand[i][j].size();k++)
                    {
                        bool flag = 1;
                        for(r=0;flag && r<9;r++)
                        {
                            if(j!=r && board[i][r]=='.')
                            {
                                for(k0=0;flag && k0<cand[i][r].size();k0++)
                                {
                                    if(cand[i][r][k0]==cand[i][j][k])
                                        flag = 0;
                                }
                            }
                        }

                        for(c=0;flag && c<9;c++)
                        {
                            if(i!=c && board[c][j]!='.')
                            {
                                for(k0=0;flag && k0<cand[c][j].size();k0++)
                                {

                                    if(cand[c][j][k0]==cand[i][j][k])
                                        flag = 0;
                                }
                            }
                        }
                        for(r=(j/3)*3;flag && r<(j/3)*3+3;r++)
                        {
                            for(c=(i/3)*3;flag && c<(i/3)*3+3;c++)
                            {
                                if((c!=i || r!=j) && board[c][r]!='.')
                                {
                                    for(k0=0;flag && k0<cand[c][r].size();k0++)
                                    {

                                        if(cand[c][r][k0]==cand[i][j][k])
                                            flag = 0;
                                    }
                                }
                            }
                        }
                        if(flag)
                        {
                            board[i][j] = cand[i][j][k];
                            cand[i][j].erase(cand[i][j].begin(),cand[i][j].end());
                            res = 1;
                        }
                    }
                }
            }
        }
        return res;
    }
    int eval(vector<vector<char> >& board, vector<vector<vector<char> > >& cand)
    {
        int i,j;
        int flag = 0;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    if(cand[i][j].size()==1)
                    {
                        board[i][j] = cand[i][j][0];
                        cand[i][j].erase(cand[i][j].begin());
                        flag = 1;
                    }
                }
            }
        }
        return flag;
    }
    bool solved(vector<vector<char> >& board)
    {
        int i,j;
        int flag = 1;
        for(i = 0;flag && i<9;i++)
        {
            for(j = 0;flag && j<9;j++)
            {
                if(board[i][j]=='.')
                    flag = 0;
            }
        }
        return flag;
    }
    void trial(vector<vector<char> >& board,vector<vector<vector<char> > >& cand) //blackboard approach
    {
        vector<vector<char> > tempB;
        vector<vector<vector<char> > > tempC;
        int r,c,k;
        bool flag,error;
        int res;

        for(r = 0;r<9;r++)
        {
            for(c = 0;c<9;c++)
            {
                if (cand[r][c].size()!=0)
                {
                    k = 0;
                    int kend = cand[r][c].size();
                    while(k<kend)
                    {
                    startTrial:
                        tempB = board;
                        tempC = cand;

                        if(k==kend)
                            break;
                        tempB[r][c] = cand[r][c][k];
                        tempC[r][c].erase(tempC[r][c].begin(),tempC[r][c].end());

                        update(tempB,tempC);
                        res = eval(tempB,tempC);
                        while(res)
                        {
                            update(tempB,tempC);
                            res = eval(tempB,tempC);

                        }
                        error = err(tempB,tempC);
                        if(error == 0)
                        {
                            cand[r][c].erase(cand[r][c].begin()+k);
                            kend-=1;
                            goto startTrial;
                        }
                        flag = solved(tempB);

                        if (flag == 0)
                        {
                            res = update2(tempB,tempC);

                            while(res)
                            {
                                update(tempB,tempC);
                                res = update2(tempB,tempC);
                    //            cout<<res<<endl;
                            }
                            if(error == 0)
                            {
                                cand[r][c].erase(cand[r][c].begin()+k);
                                kend-=1;
                                goto startTrial;
                            }
                        }
                    k+=1;
                    }
                }
            }
        }
    }
    bool err(vector<vector<char> >& board,vector<vector<vector<char> > >& cand)
    {
        int i,j;
        bool flag = 1;
        for(i = 0;flag && i<9;i++)
        {
            for(j = 0;flag && j<9;j++)
            {
                if(board[i][j]=='.' && cand[i][j].size() == 0)
                    flag = 0;
            }
        }
        return flag;
    }

int main()
{
    string inp[9] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    vector<vector<char> > board(9,vector<char>(0,0));
    for(int i = 0; i<9; i++)
    {

        board[i]=vector<char>(inp[i].c_str(),inp[i].c_str()+inp[i].length());
    }

    solveSudoku(board);

    return 0;
}
