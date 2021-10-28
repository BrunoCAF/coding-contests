class Solution:
    def tribonacci(self, n: int) -> int:
        w = -0.5 + (((3.0)**(0.5))*0.5)*1j
        x = -(((3.0)**(0.5))*0.5) + 0.5*1j
        
        R = (19+3*(33)**(.5))**(1.0/3)
        r = (19-3*(33)**(.5))**(1.0/3)
        
        l0, l1, l2 = (1 + R + r)/3, (1 + w*R + r/w)/3, (1 + R/w + w*r)/3
        
        b = ((R*R - r)*x + (r*r - R)/x)*1j/(6*(33)**(.5))
        c = ((R - r*r)*x + (r - R*R)/x)*1j/(6*(33)**(.5))
        
        a = -(b+c)
        
        #print((a*(l0)**n + b*(l1)**n + c*(l2)**n))
        
        return round((a*(l0)**n + b*(l1)**n + c*(l2)**n).real)