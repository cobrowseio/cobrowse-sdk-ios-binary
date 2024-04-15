Pod::Spec.new do |s|
    s.name = 'CobrowseIO'
    s.version = '2.29.7'
    s.summary = 'CobrowseIO SDK'
    s.description = 'CobrowseIO SDK. See cobrowse.io for more information.'
    s.license = 'Apache-2.0'
    s.homepage = 'https://cobrowse.io/docs'
    s.author = { 'Andy' => 'andy@cobrowse.io' }
    s.frameworks = 'Foundation', 'Security'
    s.ios.frameworks = 'CoreLocation', 'ReplayKit'
    s.ios.deployment_target = '11.0'
    s.osx.deployment_target = '10.13'
    s.swift_version = '5'
    s.source = { :git => 'https://github.com/cobrowseio/cobrowse-sdk-ios-binary.git', :tag => 'v'+s.version.to_s }
    s.subspec 'Extension' do |sp|
        sp.ios.vendored_frameworks = 'CobrowseIOAppExtension.xcframework'
        sp.ios.deployment_target = '11.0'
    end
    s.subspec 'Framework' do |sp|
        sp.ios.vendored_frameworks = 'CobrowseIO.framework'
        sp.ios.deployment_target = '11.0'
    end
    s.subspec 'XCFramework' do |sp|
        sp.vendored_frameworks = 'CobrowseIO.xcframework'
    end
    s.default_subspec = 'XCFramework'
end
