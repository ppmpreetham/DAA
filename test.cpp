o1 = or(p1,q1,p2)
o2 = or(p1,q1,q2)
o3 = or(p2,q2,p1)
o4 = or(p2,q2,q1)

if (o1 == o2 && o3 == o4) return true

if (o1 == 0 && onsegment(p1,p2,q1)) return true
if (o2 == 0 && onsegment(p1,q2,q1)) return true
if (o3 == 0 && onsegment(p2,p1,q2)) return true
if (o4 == 0 && onsegment(p2,q1,q2)) return true