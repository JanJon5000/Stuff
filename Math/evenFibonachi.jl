function fibonachi()
    first = 1; second = 2;
    switch = false
    ans = 2
    while(first < 4*10^6 && second < 4*10^6)
        first = switch ? first : first + second
        second = switch ? first + second : second
        switch = !switch
        if first > second && first%2==0 && first < 4*10^6
            ans += first
        elseif second > first && second%2==0 && second < 4*10^6
            ans += second
        end
    end
    ans
end

fibonachi()