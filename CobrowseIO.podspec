Pod::Spec.new do |s|
    s.name = 'CobrowseIO'
    s.version = '1.10.3'
    s.summary = 'CobrowseIO SDK for iOS'
    s.description = 'CobrowseIO SDK for iOS. See cobrowse.io for more information.'
    s.license = 'Apache-2.0'

    s.homepage = 'https://cobrowse.io/get-started'
    s.author = { 'Andy' => 'andy@cobrowse.io' }
    s.frameworks = 'Foundation', 'CoreLocation', 'Security'
    s.ios.deployment_target = '9.0'
    s.dependency 'Socket.IO-Client-Swift', '~> 15.0'
    s.source = { :git => 'https://github.com/cobrowseio/cobrowse-sdk-ios-binary.git', :tag => 'v'+s.version.to_s }
    s.default_subspec = 'Release'
    s.subspec 'Release' do |sp|
        sp.ios.vendored_frameworks = 'CobrowseIO.framework'
    end


end
