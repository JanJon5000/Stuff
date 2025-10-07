function multiples()
    ans = 0
    n = 1
    for i = 1:2:940000
        ans += (n*n)
        n+=2
    end
    ans
end

multiples()