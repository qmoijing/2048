#include "game.h"
#include "ui_game.h"
game::game(QWidget *parent):
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    Score=0;
    Best=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++){Square[i][j]=0;}
    }
    /*隨機產生2*/
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
    display();
}
game::~game(){delete ui;}
void game::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Right)
    {
        old_Score=Score;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++){old_Square[i][j]=Square[i][j];}
        }
        int num=0;
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
                    if(count!=0)
                    {
                        Square[i][j+count]=Square[i][j];
                        Square[i][j]=0;
                        num++;
                    }
                }
            }
            for(int j=3;j>=0;j--)
            {
                if(Square[i][j]==Square[i][j-1]&&Square[i][j]!=0)
                {
                    Square[i][j]=2*Square[i][j];
                    Square[i][j-1]=0;
                    Score=Score+Square[i][j];
                    if(Score>Best){Best=Score;}
                    num++;
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
                    if(count!=0)
                    {
                        Square[i][j+count]=Square[i][j];
                        Square[i][j]=0;
                        num++;
                    }
                }
            }
        }
        score();
        best();
        char winner=checkWin();
        if(winner=='-')
        {
            if(winner=='w'){ui->label_result->setText("YOU WIN!!");}
            if(winner=='l'){ui->label_result->setText("YOU LOSE!!");}
        }
        int zero=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(Square[i][j]==0){zero++;}
            }
        }
        if(zero>0&&num>0)
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
        display();
    }
    if(event->key()==Qt::Key_Left)
    {
        old_Score=Score;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++){old_Square[i][j]=Square[i][j];}
        }
        int num=0;
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
                    if(count!=0)
                    {
                        Square[i][j-count]=Square[i][j];
                        Square[i][j]=0;
                        num++;
                    }
                }
            }
            for(int j=0;j<3;j++)
            {
                if(Square[i][j]==Square[i][j+1]&&Square[i][j]!=0)
                {
                    Square[i][j]=2*Square[i][j+1];
                    Square[i][j+1]=0;
                    Score=Score+Square[i][j];
                    if(Score>Best){Best=Score;}
                    num++;
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
                    if(count!=0)
                    {
                        Square[i][j-count]=Square[i][j];
                        Square[i][j]=0;
                        num++;
                    }
                }
            }
        }
        score();
        best();
        char winner=checkWin();
        if(winner!='-')
        {
            if(winner=='w'){ui->label_result->setText("YOU WIN!!");}
            if(winner=='l'){ui->label_result->setText("YOU LOSE!!");}
        }
        int zero=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(Square[i][j]==0){zero++;}
            }
        }
        if(zero>0&&num>0)
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
        display();
    }
    if(event->key()==Qt::Key_Up)
    {
        old_Score=Score;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++){old_Square[i][j]=Square[i][j];}
        }
        int num=0;
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
                    if(count!=0)
                    {
                        Square[i-count][j]=Square[i][j];
                        Square[i][j]=0;
                        num++;
                    }
                }
            }
            for(int i=0;i<3;i++)
            {
                if(Square[i][j]==Square[i+1][j]&&Square[i][j]!=0)
                {
                    Square[i][j]=2*Square[i][j];
                    Square[i+1][j]=0;
                    Score=Score+Square[i][j];
                    if(Score>Best){Best=Score;}
                    num++;
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
                    if(count!=0)
                    {
                        Square[i-count][j]=Square[i][j];
                        Square[i][j]=0;
                        num++;
                    }
                }
            }
        }
        score();
        best();
        char winner=checkWin();
        if(winner!='-')
        {
            if(winner=='w'){ui->label_result->setText("YOU WIN!!");}
            if(winner=='l'){ui->label_result->setText("YOU LOSE!!");}
        }
        int zero=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(Square[i][j]==0){zero++;}
            }
        }
        if(zero>0&&num>0)
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
        display();
    }
    if(event->key()==Qt::Key_Down)
    {
        old_Score=Score;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++){old_Square[i][j]=Square[i][j];}
        }
        int num=0;
        for(int j=0;j<4;j++)
        {
            for(int i=2;i>=0;i--)
            {
                if(Square[i][j]!=0)
                {
                    int count=0;
                    for(int k=3;k>i;k--)
                    {
                        if(Square[k][j]==0){count++;}
                    }
                    if(count!=0)
                    {
                        Square[i+count][j]=Square[i][j];
                        Square[i][j]=0;
                        num++;
                    }
                }
            }
            for(int i=3;i>=0;i--)
            {
                if(Square[i][j]==Square[i-1][j]&&Square[i][j]!=0)
                {
                    Square[i][j]=2*Square[i][j];
                    Square[i-1][j]=0;
                    Score=Score+Square[i][j];
                    if(Score>Best){Best=Score;}
                    num++;
                }
            }
            for(int i=2;i>=0;i--)
            {
                if(Square[i][j]!=0)
                {
                    int count=0;
                    for(int k=3;k>i;k--)
                    {
                        if(Square[k][j]==0){count++;}
                    }
                    if(count!=0)
                    {
                        Square[i+count][j]=Square[i][j];
                        Square[i][j]=0;
                        num++;
                    }
                }
            }
        }
        score();
        best();
        char winner=checkWin();
        if(winner!='-')
        {
            if(winner=='w'){ui->label_result->setText("YOU WIN!!");}
            if(winner=='l'){ui->label_result->setText("YOU LOSE!!");}
        }
        int zero=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(Square[i][j]==0){zero++;}
            }
        }
        if(zero>0&&num>0)
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
        display();
    }
}
char game::checkWin()
{
    /*判斷2048*/
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(Square[i][j]==2048){return 'w';}
        }
    }
    /*判斷是否有空格*/
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(Square[i][j]==0){return '-';}
        }
    }
    /*判斷橫排*/
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(Square[i][j]==Square[i][j+1]){return '-';}
        }
    }
    /*判斷直排*/
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(Square[i][j]==Square[i+1][j]){return '-';}
        }
    }
    return 'l';
}
void game::display()
{
    switch(Square[0][0])
    {
        case 0:ui->label_1->setPixmap(QPixmap(":/0.png"));break;
        case 2:ui->label_1->setPixmap(QPixmap(":/2.png"));break;
        case 4:ui->label_1->setPixmap(QPixmap(":/4.png"));break;
        case 8:ui->label_1->setPixmap(QPixmap(":/8.png"));break;
        case 16:ui->label_1->setPixmap(QPixmap(":/16.png"));break;
        case 32:ui->label_1->setPixmap(QPixmap(":/32.png"));break;
        case 64:ui->label_1->setPixmap(QPixmap(":/64.png"));break;
        case 128:ui->label_1->setPixmap(QPixmap(":/128.png"));break;
        case 256:ui->label_1->setPixmap(QPixmap(":/256.png"));break;
        case 512:ui->label_1->setPixmap(QPixmap(":/512.png"));break;
        case 1024:ui->label_1->setPixmap(QPixmap(":/1024.png"));break;
        case 2048:ui->label_1->setPixmap(QPixmap(":/2048.png"));break;
    }
    switch(Square[0][1])
    {
    case 0:ui->label_2->setPixmap(QPixmap(":/0.png"));break;
    case 2:ui->label_2->setPixmap(QPixmap(":/2.png"));break;
    case 4:ui->label_2->setPixmap(QPixmap(":/4.png"));break;
    case 8:ui->label_2->setPixmap(QPixmap(":/8.png"));break;
    case 16:ui->label_2->setPixmap(QPixmap(":/16.png"));break;
    case 32:ui->label_2->setPixmap(QPixmap(":/32.png"));break;
    case 64:ui->label_2->setPixmap(QPixmap(":/64.png"));break;
    case 128:ui->label_2->setPixmap(QPixmap(":/128.png"));break;
    case 256:ui->label_2->setPixmap(QPixmap(":/256.png"));break;
    case 512:ui->label_2->setPixmap(QPixmap(":/512.png"));break;
    case 1024:ui->label_2->setPixmap(QPixmap(":/1024.png"));break;
    case 2048:ui->label_2->setPixmap(QPixmap(":/2048.png"));break;
    }
    switch(Square[0][2])
    {
    case 0:ui->label_3->setPixmap(QPixmap(":/0.png"));break;
    case 2:ui->label_3->setPixmap(QPixmap(":/2.png"));break;
    case 4:ui->label_3->setPixmap(QPixmap(":/4.png"));break;
    case 8:ui->label_3->setPixmap(QPixmap(":/8.png"));break;
    case 16:ui->label_3->setPixmap(QPixmap(":/16.png"));break;
    case 32:ui->label_3->setPixmap(QPixmap(":/32.png"));break;
    case 64:ui->label_3->setPixmap(QPixmap(":/64.png"));break;
    case 128:ui->label_3->setPixmap(QPixmap(":/128.png"));break;
    case 256:ui->label_3->setPixmap(QPixmap(":/256.png"));break;
    case 512:ui->label_3->setPixmap(QPixmap(":/512.png"));break;
    case 1024:ui->label_3->setPixmap(QPixmap(":/1024.png"));break;
    case 2048:ui->label_3->setPixmap(QPixmap(":/2048.png"));break;
    }
    switch(Square[0][3])
    {
    case 0:ui->label_4->setPixmap(QPixmap(":/0.png"));break;
    case 2:ui->label_4->setPixmap(QPixmap(":/2.png"));break;
    case 4:ui->label_4->setPixmap(QPixmap(":/4.png"));break;
    case 8:ui->label_4->setPixmap(QPixmap(":/8.png"));break;
    case 16:ui->label_4->setPixmap(QPixmap(":/16.png"));break;
    case 32:ui->label_4->setPixmap(QPixmap(":/32.png"));break;
    case 64:ui->label_4->setPixmap(QPixmap(":/64.png"));break;
    case 128:ui->label_4->setPixmap(QPixmap(":/128.png"));break;
    case 256:ui->label_4->setPixmap(QPixmap(":/256.png"));break;
    case 512:ui->label_4->setPixmap(QPixmap(":/512.png"));break;
    case 1024:ui->label_4->setPixmap(QPixmap(":/1024.png"));break;
    case 2048:ui->label_4->setPixmap(QPixmap(":/2048.png"));break;
    }
    switch(Square[1][0])
    {
    case 0:ui->label_5->setPixmap(QPixmap(":/0.png"));break;
    case 2:ui->label_5->setPixmap(QPixmap(":/2.png"));break;
    case 4:ui->label_5->setPixmap(QPixmap(":/4.png"));break;
    case 8:ui->label_5->setPixmap(QPixmap(":/8.png"));break;
    case 16:ui->label_5->setPixmap(QPixmap(":/16.png"));break;
    case 32:ui->label_5->setPixmap(QPixmap(":/32.png"));break;
    case 64:ui->label_5->setPixmap(QPixmap(":/64.png"));break;
    case 128:ui->label_5->setPixmap(QPixmap(":/128.png"));break;
    case 256:ui->label_5->setPixmap(QPixmap(":/256.png"));break;
    case 512:ui->label_5->setPixmap(QPixmap(":/512.png"));break;
    case 1024:ui->label_5->setPixmap(QPixmap(":/1024.png"));break;
    case 2048:ui->label_5->setPixmap(QPixmap(":/2048.png"));break;
    }
    switch(Square[1][1])
    {
    case 0:ui->label_6->setPixmap(QPixmap(":/0.png"));break;
    case 2:ui->label_6->setPixmap(QPixmap(":/2.png"));break;
    case 4:ui->label_6->setPixmap(QPixmap(":/4.png"));break;
    case 8:ui->label_6->setPixmap(QPixmap(":/8.png"));break;
    case 16:ui->label_6->setPixmap(QPixmap(":/16.png"));break;
    case 32:ui->label_6->setPixmap(QPixmap(":/32.png"));break;
    case 64:ui->label_6->setPixmap(QPixmap(":/64.png"));break;
    case 128:ui->label_6->setPixmap(QPixmap(":/128.png"));break;
    case 256:ui->label_6->setPixmap(QPixmap(":/256.png"));break;
    case 512:ui->label_6->setPixmap(QPixmap(":/512.png"));break;
    case 1024:ui->label_6->setPixmap(QPixmap(":/1024.png"));break;
    case 2048:ui->label_6->setPixmap(QPixmap(":/2048.png"));break;
    }
    switch(Square[1][2])
    {
    case 0:ui->label_7->setPixmap(QPixmap(":/0.png"));break;
    case 2:ui->label_7->setPixmap(QPixmap(":/2.png"));break;
    case 4:ui->label_7->setPixmap(QPixmap(":/4.png"));break;
    case 8:ui->label_7->setPixmap(QPixmap(":/8.png"));break;
    case 16:ui->label_7->setPixmap(QPixmap(":/16.png"));break;
    case 32:ui->label_7->setPixmap(QPixmap(":/32.png"));break;
    case 64:ui->label_7->setPixmap(QPixmap(":/64.png"));break;
    case 128:ui->label_7->setPixmap(QPixmap(":/128.png"));break;
    case 256:ui->label_7->setPixmap(QPixmap(":/256.png"));break;
    case 512:ui->label_7->setPixmap(QPixmap(":/512.png"));break;
    case 1024:ui->label_7->setPixmap(QPixmap(":/1024.png"));break;
    case 2048:ui->label_7->setPixmap(QPixmap(":/2048.png"));break;
    }
    switch(Square[1][3])
    {
    case 0:ui->label_8->setPixmap(QPixmap(":/0.png"));break;
    case 2:ui->label_8->setPixmap(QPixmap(":/2.png"));break;
    case 4:ui->label_8->setPixmap(QPixmap(":/4.png"));break;
    case 8:ui->label_8->setPixmap(QPixmap(":/8.png"));break;
    case 16:ui->label_8->setPixmap(QPixmap(":/16.png"));break;
    case 32:ui->label_8->setPixmap(QPixmap(":/32.png"));break;
    case 64:ui->label_8->setPixmap(QPixmap(":/64.png"));break;
    case 128:ui->label_8->setPixmap(QPixmap(":/128.png"));break;
    case 256:ui->label_8->setPixmap(QPixmap(":/256.png"));break;
    case 512:ui->label_8->setPixmap(QPixmap(":/512.png"));break;
    case 1024:ui->label_8->setPixmap(QPixmap(":/1024.png"));break;
    case 2048:ui->label_8->setPixmap(QPixmap(":/2048.png"));break;
    }
    switch(Square[2][0])
    {
    case 0:ui->label_9->setPixmap(QPixmap(":/0.png"));break;
    case 2:ui->label_9->setPixmap(QPixmap(":/2.png"));break;
    case 4:ui->label_9->setPixmap(QPixmap(":/4.png"));break;
    case 8:ui->label_9->setPixmap(QPixmap(":/8.png"));break;
    case 16:ui->label_9->setPixmap(QPixmap(":/16.png"));break;
    case 32:ui->label_9->setPixmap(QPixmap(":/32.png"));break;
    case 64:ui->label_9->setPixmap(QPixmap(":/64.png"));break;
    case 128:ui->label_9->setPixmap(QPixmap(":/128.png"));break;
    case 256:ui->label_9->setPixmap(QPixmap(":/256.png"));break;
    case 512:ui->label_9->setPixmap(QPixmap(":/512.png"));break;
    case 1024:ui->label_9->setPixmap(QPixmap(":/1024.png"));break;
    case 2048:ui->label_9->setPixmap(QPixmap(":/2048.png"));break;
    }
    switch(Square[2][1])
    {
    case 0:ui->label_10->setPixmap(QPixmap(":/0.png"));break;
    case 2:ui->label_10->setPixmap(QPixmap(":/2.png"));break;
    case 4:ui->label_10->setPixmap(QPixmap(":/4.png"));break;
    case 8:ui->label_10->setPixmap(QPixmap(":/8.png"));break;
    case 16:ui->label_10->setPixmap(QPixmap(":/16.png"));break;
    case 32:ui->label_10->setPixmap(QPixmap(":/32.png"));break;
    case 64:ui->label_10->setPixmap(QPixmap(":/64.png"));break;
    case 128:ui->label_10->setPixmap(QPixmap(":/128.png"));break;
    case 256:ui->label_10->setPixmap(QPixmap(":/256.png"));break;
    case 512:ui->label_10->setPixmap(QPixmap(":/512.png"));break;
    case 1024:ui->label_10->setPixmap(QPixmap(":/1024.png"));break;
    case 2048:ui->label_10->setPixmap(QPixmap(":/2048.png"));break;
    }
    switch(Square[2][2])
    {
    case 0:ui->label_11->setPixmap(QPixmap(":/0.png"));break;
    case 2:ui->label_11->setPixmap(QPixmap(":/2.png"));break;
    case 4:ui->label_11->setPixmap(QPixmap(":/4.png"));break;
    case 8:ui->label_11->setPixmap(QPixmap(":/8.png"));break;
    case 16:ui->label_11->setPixmap(QPixmap(":/16.png"));break;
    case 32:ui->label_11->setPixmap(QPixmap(":/32.png"));break;
    case 64:ui->label_11->setPixmap(QPixmap(":/64.png"));break;
    case 128:ui->label_11->setPixmap(QPixmap(":/128.png"));break;
    case 256:ui->label_11->setPixmap(QPixmap(":/256.png"));break;
    case 512:ui->label_11->setPixmap(QPixmap(":/512.png"));break;
    case 1024:ui->label_11->setPixmap(QPixmap(":/1024.png"));break;
    case 2048:ui->label_11->setPixmap(QPixmap(":/2048.png"));break;
    }
    switch(Square[2][3])
    {
    case 0:ui->label_12->setPixmap(QPixmap(":/0.png"));break;
    case 2:ui->label_12->setPixmap(QPixmap(":/2.png"));break;
    case 4:ui->label_12->setPixmap(QPixmap(":/4.png"));break;
    case 8:ui->label_12->setPixmap(QPixmap(":/8.png"));break;
    case 16:ui->label_12->setPixmap(QPixmap(":/16.png"));break;
    case 32:ui->label_12->setPixmap(QPixmap(":/32.png"));break;
    case 64:ui->label_12->setPixmap(QPixmap(":/64.png"));break;
    case 128:ui->label_12->setPixmap(QPixmap(":/128.png"));break;
    case 256:ui->label_12->setPixmap(QPixmap(":/256.png"));break;
    case 512:ui->label_12->setPixmap(QPixmap(":/512.png"));break;
    case 1024:ui->label_12->setPixmap(QPixmap(":/1024.png"));break;
    case 2048:ui->label_12->setPixmap(QPixmap(":/2048.png"));break;
    }
    switch(Square[3][0])
    {
    case 0:ui->label_13->setPixmap(QPixmap(":/0.png"));break;
    case 2:ui->label_13->setPixmap(QPixmap(":/2.png"));break;
    case 4:ui->label_13->setPixmap(QPixmap(":/4.png"));break;
    case 8:ui->label_13->setPixmap(QPixmap(":/8.png"));break;
    case 16:ui->label_13->setPixmap(QPixmap(":/16.png"));break;
    case 32:ui->label_13->setPixmap(QPixmap(":/32.png"));break;
    case 64:ui->label_13->setPixmap(QPixmap(":/64.png"));break;
    case 128:ui->label_13->setPixmap(QPixmap(":/128.png"));break;
    case 256:ui->label_13->setPixmap(QPixmap(":/256.png"));break;
    case 512:ui->label_13->setPixmap(QPixmap(":/512.png"));break;
    case 1024:ui->label_13->setPixmap(QPixmap(":/1024.png"));break;
    case 2048:ui->label_13->setPixmap(QPixmap(":/2048.png"));break;
    }
    switch(Square[3][1])
    {
    case 0:ui->label_14->setPixmap(QPixmap(":/0.png"));break;
    case 2:ui->label_14->setPixmap(QPixmap(":/2.png"));break;
    case 4:ui->label_14->setPixmap(QPixmap(":/4.png"));break;
    case 8:ui->label_14->setPixmap(QPixmap(":/8.png"));break;
    case 16:ui->label_14->setPixmap(QPixmap(":/16.png"));break;
    case 32:ui->label_14->setPixmap(QPixmap(":/32.png"));break;
    case 64:ui->label_14->setPixmap(QPixmap(":/64.png"));break;
    case 128:ui->label_14->setPixmap(QPixmap(":/128.png"));break;
    case 256:ui->label_14->setPixmap(QPixmap(":/256.png"));break;
    case 512:ui->label_14->setPixmap(QPixmap(":/512.png"));break;
    case 1024:ui->label_14->setPixmap(QPixmap(":/1024.png"));break;
    case 2048:ui->label_14->setPixmap(QPixmap(":/2048.png"));break;
    }
    switch(Square[3][2])
    {
    case 0:ui->label_15->setPixmap(QPixmap(":/0.png"));break;
    case 2:ui->label_15->setPixmap(QPixmap(":/2.png"));break;
    case 4:ui->label_15->setPixmap(QPixmap(":/4.png"));break;
    case 8:ui->label_15->setPixmap(QPixmap(":/8.png"));break;
    case 16:ui->label_15->setPixmap(QPixmap(":/16.png"));break;
    case 32:ui->label_15->setPixmap(QPixmap(":/32.png"));break;
    case 64:ui->label_15->setPixmap(QPixmap(":/64.png"));break;
    case 128:ui->label_15->setPixmap(QPixmap(":/128.png"));break;
    case 256:ui->label_15->setPixmap(QPixmap(":/256.png"));break;
    case 512:ui->label_15->setPixmap(QPixmap(":/512.png"));break;
    case 1024:ui->label_15->setPixmap(QPixmap(":/1024.png"));break;
    case 2048:ui->label_15->setPixmap(QPixmap(":/2048.png"));break;
    }
    switch(Square[3][3])
    {
    case 0:ui->label_16->setPixmap(QPixmap(":/0.png"));break;
    case 2:ui->label_16->setPixmap(QPixmap(":/2.png"));break;
    case 4:ui->label_16->setPixmap(QPixmap(":/4.png"));break;
    case 8:ui->label_16->setPixmap(QPixmap(":/8.png"));break;
    case 16:ui->label_16->setPixmap(QPixmap(":/16.png"));break;
    case 32:ui->label_16->setPixmap(QPixmap(":/32.png"));break;
    case 64:ui->label_16->setPixmap(QPixmap(":/64.png"));break;
    case 128:ui->label_16->setPixmap(QPixmap(":/128.png"));break;
    case 256:ui->label_16->setPixmap(QPixmap(":/256.png"));break;
    case 512:ui->label_16->setPixmap(QPixmap(":/512.png"));break;
    case 1024:ui->label_16->setPixmap(QPixmap(":/1024.png"));break;
    case 2048:ui->label_16->setPixmap(QPixmap(":/2048.png"));break;
    }
}
void game::on_pushButton_clicked()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            Square[i][j]=0;
        }
    }
    /*隨機產生2*/
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
    display();
    Score=0;
    score();
}
void game::on_pushButton_2_clicked()
{
    QApplication::exit(0);
}
void game::on_pushButton_3_clicked()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++){Square[i][j]=old_Square[i][j];}
    }
    Score=old_Score;
    score();
    display();
}
void game::score()
{
    int a,b,c,d,e;
    a=Score/10/10/10/10/10;
    b=Score/10/10/10%10;
    c=Score/10/10%10;
    d=Score/10%10;
    e=Score%10;
    switch(a)
    {
    case 0:ui->label_score->setText("0");break;
    case 1:ui->label_score->setText("1");break;
    case 2:ui->label_score->setText("2");break;
    case 3:ui->label_score->setText("3");break;
    case 4:ui->label_score->setText("4");break;
    case 5:ui->label_score->setText("5");break;
    case 6:ui->label_score->setText("6");break;
    case 7:ui->label_score->setText("7");break;
    case 8:ui->label_score->setText("8");break;
    case 9:ui->label_score->setText("9");break;
    }
    switch(b)
    {
    case 0:ui->label_score_2->setText("0");break;
    case 1:ui->label_score_2->setText("1");break;
    case 2:ui->label_score_2->setText("2");break;
    case 3:ui->label_score_2->setText("3");break;
    case 4:ui->label_score_2->setText("4");break;
    case 5:ui->label_score_2->setText("5");break;
    case 6:ui->label_score_2->setText("6");break;
    case 7:ui->label_score_2->setText("7");break;
    case 8:ui->label_score_2->setText("8");break;
    case 9:ui->label_score_2->setText("9");break;
    }
    switch(c)
    {
    case 0:ui->label_score_3->setText("0");break;
    case 1:ui->label_score_3->setText("1");break;
    case 2:ui->label_score_3->setText("2");break;
    case 3:ui->label_score_3->setText("3");break;
    case 4:ui->label_score_3->setText("4");break;
    case 5:ui->label_score_3->setText("5");break;
    case 6:ui->label_score_3->setText("6");break;
    case 7:ui->label_score_3->setText("7");break;
    case 8:ui->label_score_3->setText("8");break;
    case 9:ui->label_score_3->setText("9");break;
    }
    switch(d)
    {
    case 0:ui->label_score_4->setText("0");break;
    case 1:ui->label_score_4->setText("1");break;
    case 2:ui->label_score_4->setText("2");break;
    case 3:ui->label_score_4->setText("3");break;
    case 4:ui->label_score_4->setText("4");break;
    case 5:ui->label_score_4->setText("5");break;
    case 6:ui->label_score_4->setText("6");break;
    case 7:ui->label_score_4->setText("7");break;
    case 8:ui->label_score_4->setText("8");break;
    case 9:ui->label_score_4->setText("9");break;
    }
    switch(e)
    {
    case 0:ui->label_score_5->setText("0");break;
    case 1:ui->label_score_5->setText("1");break;
    case 2:ui->label_score_5->setText("2");break;
    case 3:ui->label_score_5->setText("3");break;
    case 4:ui->label_score_5->setText("4");break;
    case 5:ui->label_score_5->setText("5");break;
    case 6:ui->label_score_5->setText("6");break;
    case 7:ui->label_score_5->setText("7");break;
    case 8:ui->label_score_5->setText("8");break;
    case 9:ui->label_score_5->setText("9");break;
    }
}
void game::best()
{
    int a,b,c,d,e;
    a=Best/10/10/10/10/10;
    b=Best/10/10/10%10;
    c=Best/10/10%10;
    d=Best/10%10;
    e=Best%10;
    switch(a)
    {
    case 0:ui->label_best->setText("0");break;
    case 1:ui->label_best->setText("1");break;
    case 2:ui->label_best->setText("2");break;
    case 3:ui->label_best->setText("3");break;
    case 4:ui->label_best->setText("4");break;
    case 5:ui->label_best->setText("5");break;
    case 6:ui->label_best->setText("6");break;
    case 7:ui->label_best->setText("7");break;
    case 8:ui->label_best->setText("8");break;
    case 9:ui->label_best->setText("9");break;
    }
    switch(b)
    {
    case 0:ui->label_best_2->setText("0");break;
    case 1:ui->label_best_2->setText("1");break;
    case 2:ui->label_best_2->setText("2");break;
    case 3:ui->label_best_2->setText("3");break;
    case 4:ui->label_best_2->setText("4");break;
    case 5:ui->label_best_2->setText("5");break;
    case 6:ui->label_best_2->setText("6");break;
    case 7:ui->label_best_2->setText("7");break;
    case 8:ui->label_best_2->setText("8");break;
    case 9:ui->label_best_2->setText("9");break;
    }
    switch(c)
    {
    case 0:ui->label_best_3->setText("0");break;
    case 1:ui->label_best_3->setText("1");break;
    case 2:ui->label_best_3->setText("2");break;
    case 3:ui->label_best_3->setText("3");break;
    case 4:ui->label_best_3->setText("4");break;
    case 5:ui->label_best_3->setText("5");break;
    case 6:ui->label_best_3->setText("6");break;
    case 7:ui->label_best_3->setText("7");break;
    case 8:ui->label_best_3->setText("8");break;
    case 9:ui->label_best_3->setText("9");break;
    }
    switch(d)
    {
    case 0:ui->label_best_4->setText("0");break;
    case 1:ui->label_best_4->setText("1");break;
    case 2:ui->label_best_4->setText("2");break;
    case 3:ui->label_best_4->setText("3");break;
    case 4:ui->label_best_4->setText("4");break;
    case 5:ui->label_best_4->setText("5");break;
    case 6:ui->label_best_4->setText("6");break;
    case 7:ui->label_best_4->setText("7");break;
    case 8:ui->label_best_4->setText("8");break;
    case 9:ui->label_best_4->setText("9");break;
    }
    switch(e)
    {
    case 0:ui->label_best_5->setText("0");break;
    case 1:ui->label_best_5->setText("1");break;
    case 2:ui->label_best_5->setText("3");break;
    case 4:ui->label_best_5->setText("4");break;
    case 5:ui->label_best_5->setText("5");break;
    case 6:ui->label_best_5->setText("6");break;
    case 7:ui->label_best_5->setText("7");break;
    case 8:ui->label_best_5->setText("8");break;
    case 9:ui->label_best_5->setText("9");break;
    }
}
