len = gets.strip.to_i
str = gets.strip

diff = false

last_char = str[0]
skip = true
out = nil
str.each_char do |c|
    if skip
        skip = false
        next
    end
    if c != last_char
        out = last_char + c
        break
    end
end

if out.nil?
    puts "NO"
else
    puts "YES"
    puts out
end
