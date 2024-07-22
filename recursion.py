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
#         left_arm = left(m)
#         right_arm = right(m)
#         return (length(left_arm) * total_mass(end(left_arm)) == length(right_arm) * total_mass(end(right_arm))) \
#                and balanced(end(left_arm)) and balanced(end(right_arm))


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

# def pair(x, y):
#     """Return a function that represents a pair."""
#     def get(index):
#         if index == 0:
#             return x
#         elif index == 1:
#             return y
#     return get
    

# print(p1(1))


# LAB 6 - ITERATORS, GENERATROS

# def count_occurrences(t, n, x):
#     if not n: return 0
#     item = next(t)
#     return int(item == x) + count_occurrences(t, n-1, x)

# s = iter([10, 9, 10, 9, 9, 10, 8, 8, 8, 7])
# print(count_occurrences(s, 10, 7))

# u = iter([3, 2, 2, 2, 1, 2, 1, 4, 4, 5, 5, 5])
# print(count_occurrences(u, 1, 3))
# print(count_occurrences(u, 3, 2))
# print(list(u))


# def hailstone(n):
#     yield n
#     while (n != 1):
#         if n & 1:
#             n = n * 3 + 1
#         else:
#             n //= 2
#         yield n

# extra challenge:
# def hailstone(n):
#     yield n
#     if n == 1: return
#     if n & 1:
#         yield from hailstone(n * 3 + 1)
#     else:
#         yield from hailstone(n // 2)

# for num in hailstone(10):
#     print(num)


# def merge(incr_a, incr_b):

#     iter_a, iter_b = iter(incr_a), iter(incr_b)
#     next_a, next_b = next(iter_a, None), next(iter_b, None)

#     while next_a!=None and next_b!=None:
#         if next_a < next_b:
#             yield next_a
#             next_a = next(iter_a, None)
#         elif next_a > next_b:
#             yield next_b
#             next_b = next(iter_b, None) 
#         else:
#             next_a = next(iter_a, None) # advance any one of both

#     # print what's left
#     while next_a:
#         next_a = next(iter_a, None)
#         if next_a: yield next_a
#     while next_b:
#         next_b = next(iter_b, None)
#         if next_b: yield next_b

# m = merge([0, 2, 4, 6, 8, 10, 12, 14], [0, 3, 6, 9, 12, 15])
# print(list(m))

# def big(n):
#     k = 0
#     while True: yield k; k += n
# bigm = merge(big(2), big(3))
# iter2 = big(2)
# iter3 = big(3)

# print(f" second answer: {[next(bigm) for _ in range(11)]}")


# def deep_map(f, s):
#     for index, item in enumerate(s):
#         if type(item) == list:
#             deep_map(f, item)
#         else:
#             s[index] = f(s[index])
# """ why are they making us use iterator here?
# I'm confused. This is probably a wrong way to do this.
# """
# six = [1, 2, [3, [4], 5], 6]
# deep_map(lambda x: x * x, six)
# print(six)




# class VendingMachine:
#     """A vending machine that vends some product for some price.

#     >>> v = VendingMachine('candy', 10)
#     >>> v.vend()
#     'Nothing left to vend. Please restock.'
#     >>> v.add_funds(15)
#     'Nothing left to vend. Please restock. Here is your $15.'
#     >>> v.restock(2)
#     'Current candy stock: 2'
#     >>> v.vend()
#     'Please add $10 more funds.'
#     >>> v.add_funds(7)
#     'Current balance: $7'
#     >>> v.vend()
#     'Please add $3 more funds.'
#     >>> v.add_funds(5)
#     'Current balance: $12'
#     >>> v.vend()
#     'Here is your candy and $2 change.'
#     >>> v.add_funds(10)
#     'Current balance: $10'
#     >>> v.vend()
#     'Here is your candy.'
#     >>> v.add_funds(15)
#     'Nothing left to vend. Please restock. Here is your $15.'

#     >>> w = VendingMachine('soda', 2)
#     >>> w.restock(3)
#     'Current soda stock: 3'
#     >>> w.restock(3)
#     'Current soda stock: 6'
#     >>> w.add_funds(2)
#     'Current balance: $2'
#     >>> w.vend()
#     'Here is your soda.'
#     """
#     "*** YOUR CODE HERE ***"
    
#     def __init__(self, _item, _price) -> None:
#         self.item = _item
#         self.stock = 0
#         self.price = _price
#         self.balance = 0

#     def add_funds(self, x) -> str:
#         self.balance += x
#         if not self.stock:
#             return self.vend()
#         else:
#             return f"Current balance: ${self.balance}"

#     def restock(self, x) -> str:
#         self.stock += x
#         return f"Current {self.item} stock: {self.stock}"

#     def vend(self) -> str:
#         if not self.stock:
#             if not self.balance:
#                 return "Nothing left to vend. Please restock."
#             else:
#                 temp = self.balance
#                 self.balance = 0
#                 return f"Nothing left to vend. Please restock. Here is your ${temp}."
#         else:
#             if self.balance < self.price:
#                 diff = self.price - self.balance
#                 return f"Please add ${diff} more funds."
#             else:
#                 change = self.balance - self.price
#                 self.balance = 0
#                 self.stock -= 1
#                 if change:
#                     return f"Here is your {self.item} and ${change} change."
#                 else:
#                     return f"Here is your {self.item}."

# v = VendingMachine('candy', 10)
# print(v.vend())
# print(v.add_funds(15))
# print(v.restock(2))
# print(v.vend())
# print(v.add_funds(7))
# print(v.vend())
# print(v.add_funds(5))
# print(v.vend())
# print(v.add_funds(10))
# print(v.vend())
# print(v.add_funds(15))



# LAB 7 - OOP

# Q3 ___________________________________________________________________________

# class Account:
#     max_withdrawal = 10
#     interest = 0.02

#     def __init__(self, account_holder):
#         self.balance = 0
#         self.holder = account_holder

#     def deposit(self, amount):
#         self.balance = self.balance + amount
#         return self.balance

#     def withdraw(self, amount):
#         if amount > self.balance:
#             return "Insufficient funds"
#         if amount > self.max_withdrawal:
#             return "Can't withdraw that amount"
#         self.balance = self.balance - amount
#         return self.balance
    
#     def time_to_retire(self, amount):
#         """Return the number of years until balance would grow to amount."""
#         assert self.balance > 0 and amount > 0 and self.interest > 0
#         years = 0
#         bal = self.balance
#         while (bal < amount):
#             years += 1
#             bal *= (1+self.interest)
#         return years
    
# a = Account('John')
# print(a.deposit(10))  # 10
# print(a.balance)  # 10
# print(a.interest)  # 0.02
# print(a.time_to_retire(10.25))  # 2
# print(a.balance)  # 10
# print(a.time_to_retire(11))  # 5
# print(a.time_to_retire(100))  # 117



# Q4 ___________________________________________________________________________

# class FreeChecking(Account):
#     """A bank account that charges for withdrawals, but the first two are free!
#     >>> ch = FreeChecking('Jack')
#     >>> ch.balance = 20
#     >>> ch.withdraw(100)  # First one's free. Still counts as a free withdrawal even though it was unsuccessful
#     'Insufficient funds'
#     >>> ch.withdraw(3)    # Second withdrawal is also free
#     17
#     >>> ch.balance
#     17
#     >>> ch.withdraw(3)    # Ok, two free withdrawals is enough, as free_withdrawals is only 2
#     13
#     >>> ch.withdraw(3)
#     9
#     >>> ch2 = FreeChecking('John')
#     >>> ch2.balance = 10
#     >>> ch2.withdraw(3) # No fee
#     7
#     >>> ch.withdraw(3)  # ch still charges a fee
#     5
#     >>> ch.withdraw(5)  # Not enough to cover fee + withdraw
#     'Insufficient funds'
#     """
#     withdraw_fee = 1
#     free_withdrawals = 2

#     "*** YOUR CODE HERE ***"
#     def withdraw(self, amount):
#         if self.free_withdrawals:
#             self.free_withdrawals -= 1
#             return super().withdraw(amount)
#         else:
#             self.balance -= self.withdraw_fee # the fee is always decremented
#             return super().withdraw(amount)

# ch = FreeChecking('Jack')
# ch.balance = 20
# print(ch.withdraw(100))  # 'Insufficient funds'
# print(ch.withdraw(3))    # 17
# print(ch.balance)  # 17
# print(ch.withdraw(3))    # 13
# print(ch.withdraw(3))    # 9
# ch2 = FreeChecking('John')
# ch2.balance = 10
# print(ch2.withdraw(3))  # 7
# print(ch.withdraw(3))  # 5
# print(ch.withdraw(5))  # 'Insufficient funds'



# Q5 ___________________________________________________________________________

# class Transaction:
#     def __init__(self, id, before, after):
#         self.id = id
#         self.before = before
#         self.after = after

#     def changed(self):
#         return self.before != self.after

#     def report(self):
#         msg = 'no change'
#         if self.changed():
#             if self.after > self.before:
#                 msg = f"increased {self.before}->{self.after}"
#             else:
#                 msg = f"decreased {self.before}->{self.after}"

#         return str(self.id) + ': ' + msg

# class BankAccount:

#     def __init__(self, account_holder):
#         self.balance = 0
#         self.holder = account_holder
#         self.id = 1
#         self.transactions = []

#     def deposit(self, amount):
#         """Increase the account balance by amount, add the deposit
#         to the transaction history, and return the new balance.
#         """
#         before = self.balance
#         self.balance = self.balance + amount

#         # create transaction and add to the list
#         t = Transaction(self.id, before, self.balance)
#         self.id += 1
#         self.transactions.append(t)

#         return self.balance

#     def withdraw(self, amount):
#         """Decrease the account balance by amount, add the withdraw
#         to the transaction history, and return the new balance.
#         """
#         if amount > self.balance:
#             self.transactions.append(Transaction(self.id, self.balance, self.balance))
#             self.id += 1
#             return 'Insufficient funds'
        
#         before = self.balance
#         self.balance = self.balance - amount

#         # create transaction and add to the list
#         t = Transaction(self.id, before, self.balance)
#         self.id += 1
#         self.transactions.append(t)

#         return self.balance
    

# a = BankAccount('Eric')
# print(a.deposit(100))    # 100
# b = BankAccount('Erica')
# print(a.withdraw(30))    # 70
# print(a.deposit(10))     # 80
# print(b.deposit(50))     # 50
# print(b.withdraw(10))    # 40
# print(a.withdraw(100))   # 'Insufficient funds'
# print(len(a.transactions))  # 4
# print(len([t for t in a.transactions if t.changed()]))  # 3
# for t in a.transactions:
#     print(t.report())
# # Expected output:
# # 0: increased 0->100
# # 1: decreased 100->70
# # 2: increased 70->80
# # 3: no change

# print(b.withdraw(100))   # 'Insufficient funds'
# print(b.withdraw(30))    # 10
# for t in b.transactions:
#     print(t.report())
# # Expected output:
# # 0: increased 0->50
# # 1: decreased 50->40
# # 2: no change
# # 3: decreased 40->10



# Q6 ___________________________________________________________________________


# class Email:
#     def __init__(self, msg, sender: 'Client', recipient_name: str):
#         self.msg = msg
#         self.sender = sender
#         self.recipient_name = recipient_name

# class Server:
#     """Each Server has one instance attribute called clients that is a
#     dictionary from client names to client objects.
#     """
#     def __init__(self):
#         self.clients = {}

#     def send(self, email):
#         """Append the email to the inbox of the client it is addressed to.
#             email is an instance of the Email class.
#         """
#         self.clients[email.recipient_name].inbox.append(email)

#     def register_client(self, client: 'Client'):
#         """Add a client to the clients mapping (which is a 
#         dictionary from client names to client instances).
#             client is an instance of the Client class.
#         """
#         self.clients[client.name] = client

# class Client:
#     def __init__(self, server, name):
#         self.inbox = []
#         self.server = server
#         self.name = name
#         server.register_client(self)

#     def compose(self, message, recipient_name):
#         """Send an email with the given message to the recipient."""
#         email = Email(message, self, recipient_name)
#         self.server.send(email)

# s = Server()
# a = Client(s, 'Alice')
# b = Client(s, 'Bob')
# a.compose('Hello, World!', 'Bob')
# print(b.inbox[0].msg)  # 'Hello, World!'
# a.compose('CS 61A Rocks!', 'Bob')
# print(len(b.inbox))  # 2
# print(b.inbox[1].msg)  # 'CS 61A Rocks!'
# print(b.inbox[1].sender.name)  # 'Alice'