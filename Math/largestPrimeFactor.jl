function isPrime(num)
    for i = 2:num
        if(num%i==0 && num!=i)
            return false
        end
    end
    return true
end
function largestPrimeFactor(num)
    ans = []
    largest = 2
    while(num > 1)
        while(num%largest==0)
            push!(ans, largest)
            num/=largest
        end
        largest+=1
        while(!isPrime(largest))
            largest+=1
        end
    end
    ans[end]
end

print(largestPrimeFactor(600851475143))