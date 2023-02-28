#include <string>
#include <iostream>
#include <utility>
#include <type_traits>
#include <memory>
#include <variant>
#include <functional>

template <class T>
struct tag
{
  using type = T;
};

template <class X, class A, class B>
struct subst : tag<X>
{
};
template <class X, class A, class B>
using subst_t = typename subst<X, A, B>::type;

template <class A, class B>
struct subst<A, A, B> : tag<B>
{
};
template <class X, class A, class B>
struct subst<X &, A, B> : tag<subst_t<X, A, B> &>
{
};
template <class X, class A, class B>
struct subst<X &&, A, B> : tag<subst_t<X, A, B> &&>
{
};
template <class X, class A, class B>
struct subst<X const, A, B> : tag<subst_t<X, A, B> const>
{
};
template <class X, class A, class B>
struct subst<X volatile, A, B> : tag<subst_t<X, A, B> volatile>
{
};
template <class X, class A, class B>
struct subst<X const volatile, A, B> : tag<subst_t<X, A, B> const volatile>
{
};
template <template <class...> class Z, class... Xs, class A, class B>
struct subst<Z<Xs...>, A, B> : tag<Z<subst_t<Xs, A, B>...>>
{
};
template <template <class, size_t> class Z, class X, size_t n, class A, class B>
struct subst<Z<X, n>, A, B> : tag<Z<subst_t<X, A, B>, n>>
{
};
template <class R, class... Xs, class A, class B>
struct subst<R(Xs...), A, B> : tag<subst_t<R, A, B>(subst_t<Xs, A, B>...)>
{
};

struct own_type
{
};

template <class Sig>
struct recursive_func
{
  using func = std::function<subst_t<Sig, own_type, recursive_func>>;
  template <class... Ts>
  std::result_of_t<func const &(Ts...)>
  operator()(Ts &&...ts) const
  {
    return f(std::forward<Ts>(ts)...);
  }
  operator func const &() const & { return f; }
  operator func &() & { return f; }
  operator func() && { return std::move(f); }
  template <class F,
            class = std::enable_if_t<
                !std::is_same<recursive_func, std::decay_t<F>>::value && std::is_convertible<F, func>::value>>
  recursive_func(F &&fin) : f(fin) {}

  recursive_func(recursive_func &&) = default;
  recursive_func(recursive_func const &) = default;
  recursive_func &operator=(recursive_func &&) = default;
  recursive_func &operator=(recursive_func const &) = default;

  func *operator->() { return f; }
  func const *operator->() const { return f; }

private:
  func f;
};

template <class F>
struct y_combinator_t
{
  F f;
  template <class... Args>
  auto operator()(Args &&...args)
      -> typename std::result_of<F &(F &, Args &&...)>::type
  {
    return f(f, std::forward<Args>(args)...);
  }
};
template <class F>
y_combinator_t<std::decay_t<F>> y_combinate(F &&f)
{
  return {std::forward<F>(f)};
}

void test(std::function<void()> f)
{
  f();
  f();
  f();
  f();
}

int main()
{

  std::function<void()> func = y_combinate(recursive_func<void(own_type &)>([](auto &&self)
                                                                            {
      std::cout << "a\n";
      self = [](auto&&){ std::cout << "b\n"; }; }));

  test(func);
  func();
  test(func);
}