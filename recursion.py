# import time

# def measure_execution_time(func, *args, **kwargs):
#     """
#     Measures the execution time of a given function.
    
#     Parameters:
#         func (callable): The function to measure.
#         *args: Positional arguments to pass to the function.
#         **kwargs: Keyword arguments to pass to the function.
    
#     Returns:
#         The result of the function call and the execution time in seconds.
#     """
#     start_time = time.time()
#     result = func(*args, **kwargs)
#     end_time = time.time()
#     execution_time = end_time - start_time
#     print(f"Execution time: {execution_time:.6f} seconds; answer: {result}")


# def max_subseq(n, t):
#     return helper(0, n, t)

# def helper(built, left, t):
#     if not left or not t: 
#         return built
    
#     Max = 0
#     length = len(str(left)) - 1
    
#     if t > len(str(left)):
#         diff = t-len(str(left))
#         Max = helper(built*(10 ** diff), left, t-diff)
#         t -= diff

#     while left:
#         length = len(str(left)) - 1
#         t_to_pass = t-1 if (t-1) <= length else length
#         temp = helper(built*10 + left // (10**length), left % (10**length), t_to_pass)
#         left %= (10**length)
#         Max = max(Max,temp)

#     return Max


# def max_subseq2(n,t):
#     def max_dig(k):
#         if k//10==0: 
#             return k
#         else: 
#             return max_dig(k//100*10+max(k%10,k//10%10))
#     def search(digit, num):
#         length = len(str(num)) - 1
#         if not num or digit == (num // (10 ** length)):
#             return 1
#         else:
#             return 1 + search(digit, num % (10 ** length))
            
#     if t==0: # if theres no t, end adding.
#         return 0
#     elif n//(10**t)==0: return n
#     else: 
#         a = n//(10**(t-1))
#         md = max_dig(a)
#         pos = search(md, n)
#         return (10**(t-1))*md + max_subseq2(n%(10**(len(str(n))-pos)), t-1)

# print("answers:")
# measure_execution_time(max_subseq, 1200523323525234294, 15)
# measure_execution_time(max_subseq2, 1200523323525234294, 15)




# def flatten(s):
#     ans = []

#     for i in s:
#         if type(i) == list:
#             ans.extend(flatten(i))
#         else:
#             ans.append(i)        
    
#     return ans
        
# deep = [1, [[2], 3], 4, [5, 6]]
# print(flatten(deep)



# def merge(s, t):
#     if not s:
#         return t
#     elif not t:
#         return s
#     else:
#         if s[0] < t[0]:
#             return s[0:1] + merge(s[1:], t[:])
#         else:
#             return t[0:1] + merge(s[:], t[1:])

# print(merge([2, 3, 4], [2, 4, 6]))



# def size_of_tree(t):
#     # base case
#     if is_leaf(t):
#         return 1
#     total = 0
#     for branch in branches(t):
#         total += size_of_tree(branch)
#     return total + 1
        


# def replace_loki_at_leaf(t, lokis_replacement):
#     # if leaf, return copied leaf 
#     if is_leaf(t):
#         if label(t) == "loki": return tree(lokis_replacement)
#         else: return tree(label(t))
#     # if non leaf,
#     newtree = [label(t)]
#     for branch in branches(t):
#         subtree = replace_loki_at_leaf(branch, lokis_replacement) 
#         newtree.append(subtree)
#     return newtree



# def pascal(row, column):
#     if (column > row):
#         return 0
#     if (column == 0): 
#         return 1
#     else:
#         return pascal(row-1, column-1) + pascal(row-1, column)

# print(pascal(0,5))
# print(pascal(4,2))


# def insert_items(s, before, after):
#     if not s:
#         return s
#     if s[0] != before:
#         return s[0:1] + insert_items(s[1:], before, after)
#     else:
#         return s[0:1] + [after] + insert_items(s[1:], before, after)


# double_s = [1, 2, 1, 2, 3, 3]
# double_s = insert_items(double_s, 3, 3)
# print(double_s)



# def planet(mass):
#     """Construct a planet of some mass."""
#     assert mass > 0
#     "*** YOUR CODE HERE ***"
#     data = ['planet', mass]
#     return data

# def mass(p):
#     assert is_planet(p)
#     return p[1]


# def balanced(m):
#     if is_planet(m):
#         return True
#     elif is_mobile(m):
#         return  (length(left(m)*total_mass(end(left(m)))) == length(right(m)*total_mass(end(right(m))))) \
#                 and balanced(end(left(m))) and balanced(end(right(m)))
    


# def berry_finder(t):
#     # base leaf
#     if is_leaf(t):
#         if label(t) == 'berry': return True
#         else:                   return False
#     # recursive - tree
#     elif is_tree(t):
#         for branch in branches(t):
#             if berry_finder(branch):
#                 return True
#     return False
    


# def max_path_sum(t):
#     if is_leaf(t):
#         return label(t)
    
#     Max = 0
#     for branch in branches(t):
#         temp = max_path_sum(branch)
#         Max = Max if Max > temp else temp
#     return label(t) + Max



# def minimum_mewtations(typed, source, limit):
#     # BASE CASES
#     if typed == source: return 0
#     if not limit: return 1

#     if not typed: return len(source)
#     if not source: return len(typed)
    
#     # RECURSIVE CASE
#     # if the first char is equal, just check the remaining
#     if typed[0] == source[0]:
#         return minimum_mewtations(typed[1:], source[1:], limit)

#     # else, 
#     return 1 + min(minimum_mewtations(typed, source[1:], limit - 1),
#                     minimum_mewtations(typed[1:], source, limit - 1),
#                     minimum_mewtations(typed[1:], source[1:], limit - 1))


# print(minimum_mewtations("ckiteusabcdefghijklm", "kittensnopqrstuvwxyz", 2) > 2)




# def partial_reverse(s, start):
#     l = start; r = len(s)-1
#     while (l < r):
#         s[l], s[r] = s[r], s[l]
#         l += 1; r -= 1

# a = [1, 2, 3, 4, 5, 6, 7]
# partial_reverse(a, 2)
# partial_reverse(a, 5)
# print(a)


# def group_by(s, fn):
#     grouped = {}
#     for item in s:
#         key = fn(item)
#         if key in grouped:
#             grouped[key].append(item)
#         else:
#             grouped[key] = [item]
#     return grouped


# def distance(city_a, city_b):
#     x1 = get_lat(city_a); x2 = get_lat(city_b)
#     y1 = get_lon(city_a); y2 = get_lon(city_b)
#     return sqrt((x1 - x2)**2 + (y1 - y2)**2)


# def closer_city(lat, lon, city_a, city_b):
#     pos = make_city('pos', lat, lon)
#     return city_a if distance(city_a, pos) < distance(city_b, pos) else city_b

