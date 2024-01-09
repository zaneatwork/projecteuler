# If the numbers 1 to 5 are written out in words: one, two, three, four, five,
# then there are letters used in total.
# If all the numbers from one to one thousand inclusive were written out in
# words, how many letters would be used?
#
# NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
# forty-two) contains letters and (one hundred and fifteen) contains letters.
# The use of "and" when writing out numbers is in compliance with British usage.

ones = [
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
]
teens = [
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
]
tens = [
    "",
    "",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety",
]


def text_for_num(num):
    text = ""
    if num < 10:
        text += ones[num]
    elif num < 20:
        text += teens[num % 10]
    elif num < 100:
        text += tens[num // 10]
        text += text_for_num(num % 10)
    elif num < 1000:
        text += ones[num // 100] + "hundred"
        if num % 100 > 0:
            text += "and" + text_for_num(num % 100)
    elif num < 10_000:
        text += ones[num // 1000] + "thousand"
        text += text_for_num(num % 1000)
    return text


print(len("".join([text_for_num(num) for num in range(1, 1001)])))
