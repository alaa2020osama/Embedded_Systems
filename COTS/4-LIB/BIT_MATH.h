#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Var,BitNo) (Var=Var|(1<<BitNo))
#define CLR_BIT(Var,BitNo) (Var=Var&(~(1<<BitNo)))
#define TOGGLE_BIT(Var,BitNo) (Var=Var^(1<<BitNo))
#define GET_BIT(Var,BitNo) (1&(Var>>BitNo))

#endif
