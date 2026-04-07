# Exercícios Cálculo Lambda

### Aluno: Guilherme Hoerning Reinert

### 1\)
a\)
```
a b c d = ((((a)b)c)d)
```
b\)
```
(λq.λi.q)
-> λqλi.q
```
c\)
```
(λxλyλz.x z(yz))
-> λxλyλz.x z(yz)
```
### 2\)
a\)
```
(λs.szλq.sq)
-> (λs.sz)(λq.sq)

=> z livre, s ligada a (λs.sz) e q ligada em (λq.sq)
```
b\)
```
(λs.sz) λq.w λw.wqzs
-> (λs.sz)(λq.w)(λw.wqzs)

=> q e z livres, s ligada em (λs.sz) e w ligada em (λw.wqzs)
```
c\)
```
(λs.s)(λq.q s)

=> s ligada em (λs.s) e q ligada em (λq.q s)
```  
d\)
```
λz.((λs.sq)(λq.qz))λz.zz

=> z ligada em (λz.zz), s ligada em (λs.sq) e q ligada em (λq.qz)
```
### 3\)
a\) 
```
(λz.z)(λq.qq)(λs.sq)
-> ((λz.z)(λq.qq))(λs.sq)
-> (λz.z)((λs.sq)q)
-> (λz.z)(qq)
```
b\)
```
(λsλq.sqq)(λa.a)b
-> (λsλq.sqq)b
-> λq.bqq
```
c\)
```
(λsλq.sqq)(λx.x)c
-> λq.cqq
```
d\)
```
((λs.ss)(λq.q))(λr.r)
-> ((λq.q)(λq.q))(λr.r)
-> (λq.q)(λr.r)
-> λr.r
```

### 4\)

a\)
```
(λx.x)5
-> 5
```
b\)
```
(λx.x+10)42
-> (42 + 10)
-> 52
```
c\)
```
(λf.f(f 10))(λx.x+2)
-> (λx.x+2(λx.x+2))10
-> λx.x+2(10+2)
-> 12 + 2
-> 14
```
d\)
```
(λf.f)(λx.x)51
-> (λf.f)51
-> 51
```
### 5\)
```
;-; PLUS TWO ONE:

λmλnλfλx.mf(nfx)(λaλb.ab)(λcλd.c(cd))
-> (λnλfλx.(λaλb.ab)(f(nfx)))(λcλd.c(cd))
-> λfλx.(λaλb.ab)(f(λcλd.c(cd))fx)
-> λfλx(λaλb.ab)(f(λd.f(fd)x))
-> λfλx(λaλb.ab)(f(f(fx)))
-> λfλx(λb.fb)(f(fx))
-> λfλx(f(f(fx)))
```

