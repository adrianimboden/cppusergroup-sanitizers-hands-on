lambda { |stdout,stderr,status|
  output = stdout + stderr
  return :red   if /(.*)failed(.*)/.match(output)
  return :green if true
  return :amber
}
