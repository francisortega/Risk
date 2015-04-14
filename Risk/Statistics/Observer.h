
#ifndef OBSERVER_H
#define	OBSERVER_H

class Observer {
public:
    Observer();
    Observer(const Observer& orig);
    virtual ~Observer();
    virtual void update()=0;
private:

};

#endif	/* OBSERVER_H */

