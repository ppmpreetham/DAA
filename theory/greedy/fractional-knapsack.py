def frac_knapsack(w: list, v: list, capacity):
    k = [(v[i]/w[i],v[i],w[i]) for i in range(len(w))]
    k.sort(key=lambda k: k[0], reverse=True)
    total = 0
    
    for ratio, _, weight in k:
        if capacity >= weight:
            total += weight
            capacity -= weight
        else:
            total += ratio*capacity
            break

    return total

print(frac_knapsack([1,3,54],[2,5,6],1))