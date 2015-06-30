# Late

Late uses C bindings to calculate time and convert time formats faster.

## How much faster?
Comparing getting epoch time in Ruby vs. Late using [benchmark-ips](https://github.com/evanphx/benchmark-ips):
```
Calculating -------------------------------------
                   C    112.850k i/100ms
                Ruby    80.309k i/100ms
-------------------------------------------------
                   C      4.516M (± 3.3%) i/s -     22.570M
                Ruby      1.895M (± 2.9%) i/s -      9.476M

Comparison:
                   C:  4515848.4 i/s
                Ruby:  1894654.8 i/s - 2.38x slower
```

## Installation

Add this line to your application's Gemfile:

    gem 'late'

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install late

## Usage

Epoch to DateTime with default format

```
Late.httpdate(Time.now.to_i)
=> "Mon, 29 Jun 2015 04:47:33 GMT"
```

Epoch to DateTime with custom format

```
Late.pp(Time.now.to_i,"%a, %d %b %Y GMT")
=> "Mon, 29 Jun 2015 GMT"
```

Current DateTime in epoch
```
Late.epoch
=> 1435536000
```

## Contributing

1. Fork it
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request
