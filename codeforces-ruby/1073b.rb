n = gets.strip.to_i

arr = gets.strip.split(' ').map(&:to_i)

query = gets.strip.split(' ').map(&:to_i)

max = nil

pos = Hash.new()

arr.each_with_index do |a, i|
    pos[a] = i + 1
end

out = []
query.each do |q|
    if max.nil?
        max = pos[q]
        out << max
    else
        val = pos[q]
        if val > max
            out << (val - max)
            max = val
        else
            out << 0
        end
    end
end

puts out.join(' ')
