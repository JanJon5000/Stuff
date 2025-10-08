function multiples()
    counter = 0
    for i = 1:999   
        if i%3== 0 || i%5 == 0
            counter += i
        end
    end
    counter
end

multiples()