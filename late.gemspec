# -*- encoding: utf-8 -*-
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'late/version'

Gem::Specification.new do |gem|
  gem.name          = "late"
  gem.version       = Late::VERSION
  gem.authors       = ["Andrew De Ponte"]
  gem.email         = ["cyphactor@gmail.com"]
  gem.description   = %q{Late is a gem that provides extremely fast C binding based time methods}
  gem.summary       = %q{Lighting fast C binding based time methods in ruby}
  gem.homepage      = ""

  gem.files         = `git ls-files`.split($/) + Dir.glob('ext/**/*.{c,h,rb}')
  gem.extensions    = ['ext/late/extconf.rb']
  gem.test_files    = gem.files.grep(%r{^(test|spec|features)/})
  gem.require_paths = ["lib"]
end
