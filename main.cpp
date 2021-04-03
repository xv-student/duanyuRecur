#include <iostream>
#include "player/player.h"
#include "informOfStra/informOfStrategy.h"
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <direct.h>
#include "./function4game/function4game.h"


using namespace std;
const int num_of_startegy=256;
const int side_of_startegy=16;
const int num_of_player=128*128;
const int length_of_side=128;
const int bate=30;

int main() {
    string lin;
    function4game function;
    ifstream in("G:\\APPLICATION DATA\\CLion\\duanyuRecur\\stableDistrubute.txt");
    srand((int)time(NULL));
    cout<<"------初始化开始------"<<endl;
    double b[7]={1.2,1.6,2,3,3.5,4,4.5};
   informOfStrategy *inform=new informOfStrategy[num_of_startegy];
   player ply[num_of_player];
   player ply_swap[num_of_player];
    for (int i = 0; i < num_of_player; ++i) {
        int x,y;
        x=i/length_of_side;
        y=i-x*length_of_side;
        //左邻居
        ply[i].setNeighbourLeft(x*length_of_side+((y-1+length_of_side)%length_of_side));
        ply_swap[i].setNeighbourLeft(x*length_of_side+((y-1+length_of_side)%length_of_side));
        //右邻居
        ply[i].setNeighbourRight(x*length_of_side+((y+1+length_of_side)%length_of_side));
        ply_swap[i].setNeighbourRight(x*length_of_side+((y+1+length_of_side)%length_of_side));
        //上邻居
        ply[i].setNeighbourUp(((x-1+length_of_side)%length_of_side)*length_of_side+y);
        ply_swap[i].setNeighbourUp(((x-1+length_of_side)%length_of_side)*length_of_side+y);
        //下邻居
        ply[i].setNeighbourDown(((x+1+length_of_side)%length_of_side)*length_of_side+y);
        ply_swap[i].setNeighbourDown(((x+1+length_of_side)%length_of_side)*length_of_side+y);

    }




    for (int i = 0; i <7 ; ++i) {
        cout<<"HelloWorld2"<<endl;
        for (int j = 0; j <num_of_startegy ; ++j) {
            getline(in,lin);
            vector<string> res=function.split(lin,",");
            double cooperation_rate=0,payoff=0;
            cooperation_rate=/*stod(res[0])*0+*/stod(res[1])*0.5+stod(res[2])*0.5+stod(res[3])*1;
            payoff=(b[i]-1)*stod(res[0]) + (-1)*stod(res[1]) +b[i]*stod(res[2]) +0*stod(res[3]);
            inform[j].setPayoff(payoff);
            inform[j].setCooperationRate(cooperation_rate);
        }

        string folderPath1=".\\..\\Result\\"+to_string(b[i]);
        string path_and_filename1=".\\..\\Result\\"+to_string(b[i])+"\\"+"numOfPlayer.txt";
        string path_and_filename2=".\\..\\Result\\"+to_string(b[i])+"\\"+"average_cooperattion_rate.txt";
        if (0!=access(folderPath1.c_str(),0)){
            mkdir(folderPath1.c_str());
        }

        ofstream out(path_and_filename1);
        ofstream out2(path_and_filename2);

        for (int k = 0; k <100 ; ++k) {

            long int sum_number_of_player[16]={0};
            long  double sum_of_cooperation_rate=0;
            //初始化策略分布
            int count[16]={0};
            for (int j = 0; j < num_of_player; ++j) {
                int var;
                do {
                    var=rand()%16;
                }while (count[var]>=num_of_player/16);
                ply[j].setStrategy(var);
                ply_swap[j].setStrategy(var);
                count[var]++;
              //  cout<<ply_swap[j].getStrategy()<<endl;
            }

            
            for (int l = 0; l <40000 ; ++l) {
                //博弈
                for (int j = 0; j <num_of_player ; ++j) {
                  int neighb_up= ply[j].getNeighbourUp();
                  int neighb_down=ply[j].getNeighbourDown();
                  int neighb_left=ply[j].getNeighbourLeft();
                  int neighb_right=ply[j].getNeighbourRight();

                int up=ply[j].getStrategy()*16+ply[neighb_up].getStrategy();
                int down=ply[j].getStrategy()*16+ply[neighb_down].getStrategy();
                int left=ply[j].getStrategy()*16+ply[neighb_left].getStrategy();
                int right=ply[j].getStrategy()*16+ply[neighb_right].getStrategy();

                double payoff_up = inform[up].getPayoff();
                double payoff_down =inform[down].getPayoff();
                double payoff_left = inform[left].getPayoff();
                double payoff_right =inform[right].getPayoff();

                ply_swap[j].setPayoff((payoff_up+payoff_down+payoff_left+payoff_right)/2);
                }
                //学习
                for (int m = 0; m <num_of_player ; ++m) {
                    double e=0;
                    int r=rand()%4;
                    switch (r) {
                        case 0:
                            e=exp(-bate*(ply_swap[ply_swap[m].getNeighbourUp()].getPayoff()-ply_swap[m].getPayoff()));
                            if (rand()/double (RAND_MAX)<1.0/(1+e)){
                                ply_swap[m].setStrategy(ply[ply[m].getNeighbourUp()].getStrategy());
                            }

                            break;
                        case 1:
                            e=exp(-bate*(ply_swap[ply_swap[m].getNeighbourDown()].getPayoff()-ply_swap[m].getPayoff()));
                            if (rand()/double (RAND_MAX)<1.0/(1+e)){
                                ply_swap[m].setStrategy(ply[ply[m].getNeighbourDown()].getStrategy());
                            }
                            break;
                        case 2:
                            e=exp(-10*(ply_swap[ply_swap[m].getNeighbourLeft()].getPayoff()-ply_swap[m].getPayoff()));
                            if (rand()/double (RAND_MAX)<1.0/(1+e)){
                                ply_swap[m].setStrategy(ply[ply[m].getNeighbourLeft()].getStrategy());
                            }
                            break;
                        case 3:
                            e=exp(-10*(ply_swap[ply_swap[m].getNeighbourRight()].getPayoff()-ply_swap[m].getPayoff()));
                            if (rand()/double (RAND_MAX)<1.0/(1+e)){
                                ply_swap[m].setStrategy(ply[ply[m].getNeighbourRight()].getStrategy());
                            }
                            break;

                    }
                }
                for (int n = 0; n <num_of_player ; ++n) {
                    ply[n]=ply_swap[n];
                }

                //输出
                //输出不同b值，200次试验，每50轮的策略分布
                if ((l+1)%50==0){
                    string folderName=".\\..\\Result\\"+to_string(b[i])+"\\testNumber"+to_string(k);
                    string path_and_filename=".\\..\\Result\\"+to_string(b[i])+"\\testNumber"+to_string(k)+"\\"+to_string(l+1)+".txt";
                    if (0!=access(folderName.c_str(),0)){
                        mkdir(folderName.c_str());
                    }
                    ofstream out3(path_and_filename);
                    for (int j = 0; j <num_of_player ; ++j) {
                        out3<<ply[j].getStrategy()<<",";
                        if ((j+1)%128==0)out3<<endl;
                    }
                    out3.close();
                }


                //输出40000-45000的平均合作率
                if (l>=35000){
                   double temp_cooperation=0;
                    for (int j = 0; j <num_of_player; ++j) {
                       int inf_up=ply[j].getStrategy()*16+ply[ply[j].getNeighbourUp()].getStrategy();
                        int inf_down=ply[j].getStrategy()*16+ply[ply[j].getNeighbourDown()].getStrategy();
                        int inf_left=ply[j].getStrategy()*16+ply[ply[j].getNeighbourLeft()].getStrategy();
                        int inf_right=ply[j].getStrategy()*16+ply[ply[j].getNeighbourRight()].getStrategy();
                        temp_cooperation+=(inf_up+inf_down+inf_left+inf_right)/4;
                    }

                    sum_of_cooperation_rate+=temp_cooperation/num_of_player;
                }

                //输出40000-45000的策略个体的平均占比
                if (l>=35000){
                    int temp_sum[16]={0};
                    for (int j = 0; j <num_of_player ; ++j) {
                        temp_sum[ply[j].getStrategy()]++;
                    }
                    for (int m = 0; m <16 ; ++m) {
                        sum_number_of_player[m]+=temp_sum[m];
                    }
                }

            }
            cout<<"HelloWorld6"<<endl;
            for (int i1 = 0; i1 < 16; ++i1) {
                out<<sum_number_of_player[i1]<<",";
            }out<<endl;
            out2<<"round:"<<k<<" : "<<sum_of_cooperation_rate<<","<<endl;


        }
        out.close();
        out2.close();
    }
    delete []inform;
    in.close();

    //初始化策略-策略收益合作率信息
    //初始化参与者策略
    //初始化参与者邻居
    //博弈
        //博弈
        //学习
        //更新



    return 0;
}


