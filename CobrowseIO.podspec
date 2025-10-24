Pod::Spec.new do |s|
    s.name = 'CobrowseIO'
    s.version = '3.13.0'
    s.summary = 'CobrowseIO SDK'
    s.description = 'CobrowseIO SDK. See cobrowse.io for more information.'
    s.license = 'Proprietary'
    s.homepage = 'https://cobrowse.io/docs'
    s.author = { 'Andy' => 'andy@cobrowse.io' }
    s.frameworks = 'Foundation'
    s.ios.frameworks = 'ReplayKit'
    s.ios.deployment_target = '12.0'
    s.osx.deployment_target = '10.13'
    s.swift_version = '5'
    s.source = { :git => 'https://github.com/cobrowseio/cobrowse-sdk-ios-binary.git', :tag => 'v'+s.version.to_s }
    s.subspec 'Framework' do |sp|
        sp.ios.vendored_frameworks = 'CobrowseSDK.framework'
        sp.ios.deployment_target = '12.0'
    end
    s.subspec 'XCFramework' do |sp|
        sp.vendored_frameworks = 'CobrowseSDK.xcframework'
    end
    s.default_subspec = 'XCFramework'
end
