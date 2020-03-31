n = gets.strip.to_i

out = []
n.times do
    arr = gets.strip.split(' ').map(&:to_i)
    start = arr[2] - 1

    start2 = arr[3] + 1
    end2 = arr[0]

    final = (start / arr[1]).floor + (end2 / arr[1]).floor - (start2 / arr[1]).floor
    if (start2 % arr[1] == 0 && end2 % arr[1] == 0)
        final += 1
    elsif (start2 % arr[1] == 0 && end2 % arr[1] != 0)
        final += 1
    end
    out << final
end

out.each do |o|
    puts o
end
