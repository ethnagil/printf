char*ft_itoa_base(long long int n, char *base, int neg, int len)
{
  char      *str;
  long long i;

  i = ft_strlen(base);
  if (n < 0)
  {
    neg = 1;
    n = n * -1;
  }

if (n >= i)
{
  len++;
  str = ft_strjoin(ft_itoa_base(n / i, base, neg, len),
        ft_itoa_base(n % i, base, 0, len));
}
else if (n < i)
{
  if (!(str = (char *)malloc(sizeof(char) * (len + neg))))
    return (NULL);
  if (neg == 1)
  {
    str[0] = '-';
    str[0 + neg] = base[n];
    str[1 + neg] = '\0';
  }
  return (str);
}
