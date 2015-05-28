#include "keypressevent.h"
#include "game.h"

keypressevent::keypressevent(QWidget *parent,int Square[4][4]) : QWidget(parent){}
void keypressevent::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Right)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=2;j>=0;j--)
            {
                if(Square[i][j]!=0)
                {
                    int count=0;
                    for(int k=3;k>j;k--)
                    {
                        if(Square[i][k]==0){count++;}
                    }
                    Square[i][j+count]=Square[i][j];
                    Square[i][j]=0;
                }
            }
            for(int j=3;j>=0;j--)
            {
                if(Square[i][j]==Square[i][j-1]&&Square[i][j]!=0)
                {
                    Square[i][j]=2*Square[i][j];
                    Square[i][j-1]=0;
                }
            }
            for(int j=2;j>=0;j--)
            {
                if(Square[i][j]!=0)
                {
                    int count=0;
                    for(int k=3;k>j;k--)
                    {
                        if(Square[i][k]==0){count++;}
                    }
                    Square[i][j+count]=Square[i][j];
                    Square[i][j]=0;
                }
            }
        }
        desplay();
        char winner=checkWin();
        if(winner!='-')
        {
            resWindow->setWinner(winner);
            resWindow->show();
        }
        int zero=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(Square[i][j]==0){zero++;}
            }
        }
        if(zero>0)
        {
            int box;
            srand(time(NULL));
            box=rand()%16+1;
            int row=box/4,col=box%4-1;
            if(Square[row][col]!=0)
            {
                while(Square[row][col]!=0)
                {
                    box=qrand()%16+1;
                    row=box/4;
                    col=box%4-1;
                }
            }
            Square[row][col]=2;
        }
    }
    if(event->key()==Qt::Key_Left)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=1;j<4;j++)
            {
                if(Square[i][j]!=0)
                {
                    int count=0;
                    for(int k=0;k<j;k++)
                    {
                        if(Square[i][k]==0){count++;}
                    }
                    Square[i][j-count]=Square[i][j];
                    Square[i][j]=0;
                }
            }
            for(int j=0;j<3;j++)
            {
                if(Square[i][j]==Square[i][j+1]&&Square[i][j]!=0)
                {
                    Square[i][j]=2*Square[i][j+1];
                    Square[i][j+1]=0;
                }
            }
            for(int j=1;j<4;j++)
            {
                if(Square[i][j]!=0)
                {
                    int count=0;
                    for(int k=0;k<j;k++)
                    {
                        if(Square[i][k]==0){count++;}
                    }
                    Square[i][j-count]=Square[i][j];
                    Square[i][j]=0;
                }
            }
        }
        desplay();
        char winner=checkWin();
        if(winner!='-')
        {
            resWindow->setWinner(winner);
            resWindow->show();
        }
        int zero=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(Square[i][j]==0){zero++;}
            }
        }
        if(zero>0)
        {
            int box;
            srand(time(NULL));
            box=rand()%16+1;
            int row=box/4,col=box%4-1;
            if(Square[row][col]!=0)
            {
                while(Square[row][col]!=0)
                {
                    box=qrand()%16+1;
                    row=box/4;
                    col=box%4-1;
                }
            }
            Square[row][col]=2;
        }
    }
    if(event->key()==Qt::Key_Up)
    {
        for(int j=0;j<4;j++)
        {
            for(int i=1;i<4;i++)
            {
                if(Square[i][j]!=0)
                {
                    int count=0;
                    for(int k=0;k<i;k++)
                    {
                        if(Square[k][j]==0){count++;}
                    }
                    Square[i-count][j]=Square[i][j];
                    Square[i][j]=0;
                }
            }
            for(int i=0;i<3;i++)
            {
                if(Square[i][j]==Square[i+1][j]&&Square[i][j]!=0)
                {
                    Square[i][j]=2*Square[i][j];
                    Square[i+1][j]=0;
                }
            }
            for(int i=1;i<4;i++)
            {
                if(Square[i][j]!=0)
                {
                    int count=0;
                    for(int k=0;k<i;k++)
                    {
                        if(Square[k][j]==0){count++;}
                    }
                    Square[i-count][j]=Square[i][j];
                    Square[i][j]=0;
                }
            }
        }
        desplay();
        char winner=checkWin();
        if(winner!='-')
        {
            resWindow->setWinner(winner);
            resWindow->show();
        }
        int zero=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(Square[i][j]==0){zero++;}
            }
        }
        if(zero>0)
        {
            int box;
            srand(time(NULL));
            box=rand()%16+1;
            int row=box/4,col=box%4-1;
            if(Square[row][col]!=0)
            {
                while(Square[row][col]!=0)
                {
                    box=qrand()%16+1;
                    row=box/4;
                    col=box%4-1;
                }
            }
            Square[row][col]=2;
        }
    }
    if(event->key()==Qt::Key_Down)
    {
        for(int j=0;j<4;j++)
        {
            for(int i=2;i>=0;i--)
            {
                if(Square[i][j]!=0)
                {
                    int count=0;
                    for(int k=3;k>i;k++)
                    {
                        if(Square[k][j]==0){count++;}
                    }
                    Square[i+count][j]=Square[i][j];
                    Square[i][j]=0;
                }
            }
            for(int i=3;i>=0;i--)
            {
                if(Square[i][j]==Square[i-1][j]&&Square[i][j]!=0)
                {
                    Square[i][j]=2*Square[i][j];
                    Square[i-1][j]=0;
                }
            }
            for(int i=2;i>=0;i--)
            {
                if(Square[i][j]!=0)
                {
                    int count=0;
                    for(int k=3;k>i;k++)
                    {
                        if(Square[k][j]==0){count++;}
                    }
                    Square[i+count][j]=Square[i][j];
                    Square[i][j]=0;
                }
            }
        }
        desplay();
        char winner=checkWin();
        if(winner!='-')
        {
            resWindow->setWinner(winner);
            resWindow->show();
        }
        int zero=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(Square[i][j]==0){zero++;}
            }
        }
        if(zero>0)
        {
            int box;
            srand(time(NULL));
            box=rand()%16+1;
            int row=box/4,col=box%4-1;
            if(Square[row][col]!=0)
            {
                while(Square[row][col]!=0)
                {
                    box=qrand()%16+1;
                    row=box/4;
                    col=box%4-1;
                }
            }
            Square[row][col]=2;
        }
    }
}
