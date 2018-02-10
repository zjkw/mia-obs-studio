#ifndef MIASINGLETON_H
#define MIASINGLETON_H

template<class T>
class CSingleton
{
public:
    static T *getInstance();
    static void delInstance();
protected:
    CSingleton(){}
    ~CSingleton(){}
private:
    CSingleton(const CSingleton&);
    CSingleton& operator=(const CSingleton&);
private:
    static T *m_pInstance;
};

template<class T>
T *CSingleton<T>::m_pInstance = nullptr;

template<class T>
T *CSingleton<T>::getInstance()
{
    if (nullptr == m_pInstance)
    {
        if (nullptr == m_pInstance)
        {
            m_pInstance = new T();
            ::atexit(delInstance);
        }
    }

    return m_pInstance;
}

template<class T>
void CSingleton<T>::delInstance()
{
    if (nullptr != m_pInstance)
    {
        delete m_pInstance;
        m_pInstance = nullptr;
    }
}

#endif // MIASINGLETON_H
