#ifndef PULLPARAMS_H
#define PULLPARAMS_H

class PullParams
{
public:
    PullParams(){}
    ~PullParams(){}

    inline QString getRepository() const {return repository;}
    inline QString getBranch() const {return branch;}
    inline QString getLogin() const {return login;}
    inline QString getPassword() const {return password;}
    inline void setRepository(QString repository){this->repository = repository;}
    inline void setBranch(QString branch){this->branch = branch;}
    inline void setLogin(QString login){this->login = login;}
    inline void setPassword(QString password){this->password = password;}

private:
    QString repository;
    QString branch;
    QString login;
    QString password;
};

#endif // PULLPARAMS_H
