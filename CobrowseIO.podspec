Pod::Spec.new do |s|
    s.name = 'CobrowseIO'
    s.version = '2.1.0-alpha.4'
    s.summary = 'CobrowseIO SDK for iOS'
    s.description = 'CobrowseIO SDK for iOS. See cobrowse.io for more information.'
    s.license = 'Apache-2.0'
    s.homepage = 'https://cobrowse.io/docs'
    s.author = { 'Andy' => 'andy@cobrowse.io' }
    s.frameworks = 'Foundation', 'CoreLocation', 'Security', 'ReplayKit'
    s.ios.deployment_target = '9.0'
    s.dependency 'Starscream', '~> 3.1.1'
    s.dependency 'SwiftCBOR', '~> 0.4.3'
    s.swift_version = '5'
    s.source = { :git => 'https://github.com/cobrowseio/cobrowse-sdk-ios-binary.git', :tag => 'v'+s.version.to_s }
    s.subspec 'Extension' do |sp|
        sp.ios.vendored_frameworks = 'CobrowseIOAppExtension.framework'
    end
    s.subspec 'Framework' do |sp|
        sp.ios.vendored_frameworks = 'CobrowseIO.framework'
    end
    s.default_subspec = 'Framework'

end
