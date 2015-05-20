#include "gitcmdstatus.h"

GitCmdStatus::GitCmdStatus()
{

}

GitCmdStatus::~GitCmdStatus()
{

}

QStringList GitCmdStatus::getArgs()
{
    QStringList args;
    args << "status";
    return args;
}

void GitCmdStatus::procOutStr(QString str)
{
    //TODO: Replace by state automat
    QStringList list = str.split("\n");
    int i = 0;
    int state = 0;
    for (; i < list.size(); i++)
    {
        QCharRef symbol = list[i][0];
        switch (state)
        {
        case 0:
            if (symbol == '\t')
            {
                index.append(cutString(list[i]));
                state++;
            }
            break;
        case 1:
            if (symbol == '\t')
                index.append(cutString(list[i]));
            else
                state++;
            break;
        case 2:
            if (symbol == '\t')
            {
                changed.append(cutString(list[i]));
                state++;
            }
            break;
        case 3:
            if (symbol == '\t')
                changed.append(cutString(list[i]));
            else
                state++;
            break;
        case 4:
            if (symbol == '\t')
            {
                changed.append(cutString(list[i]));
                state++;
            }
            break;
        case 5:
            if (symbol == '\t')
                changed.append(cutString(list[i]));
            else
                state++;
            break;
        }
    }
}

QString GitCmdStatus::cutString(QString str)
{
    QStringList splitted = str.split(":");
    return splitted[splitted.size() - 1].trimmed();
}
